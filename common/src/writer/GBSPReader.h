#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "structures/GenesisMap.h"
#include "typeparser/EntDef.h"
#include "writer/GBSPMap.h"

class GBSPReader {
   public:
    static void read(const std::string& filename, GenesisMap& gMap) {
        std::ifstream genesisMap(filename, std::ios::in | std::ios::binary);

        if (!genesisMap.is_open()) {
            throw std::runtime_error("Can't open file");
        }

        FileHeader f;
        readFileHeader(genesisMap, f);
        readEntities(genesisMap, gMap, f.numEntities);
    }

   private:
    static void readFileHeader(std::ifstream& genesisMap, FileHeader& f) {
        genesisMap.read(reinterpret_cast<char*>(&f), sizeof(FileHeader));

        if (f.version != 1 || std::string(f.tag, 4) != "NCBF") {
            throw std::runtime_error("Invalid file format");
        }
    }
    static void readEntities(std::ifstream& genesisMap,
                             GenesisMap& gMap,
                             int numEntities) {
        for (int i = 0; i < numEntities; ++i) {
            GenesisEntity gEnt;
            readEntity(genesisMap, gEnt);
            gMap.insertEntity(gEnt);
        }
    }
    static void readEntity(std::ifstream& genesisMap, GenesisEntity& gEnt) {
        int numBrushes;
        readInt(genesisMap, numBrushes);

        for (int i = 0; i < numBrushes; ++i) {
            GenesisBrush brush;
            readBrush(genesisMap, brush);
            gEnt.insertBrush(brush);
        }

        int flags;
        readInt(genesisMap, flags);
        gEnt.setFlags(flags);  // Assuming setFlags exists

        if (flags & GenesisEntity::EntityModelMotion) {
            // Todo: read model motion, not a trivial thing...
        }

        int numKeys;
        readInt(genesisMap, numKeys);

        for (int i = 0; i < numKeys; ++i) {
            std::string key = readString(genesisMap);
            std::string value = readString(genesisMap);
            gEnt.insertKeyValue(key, value);
        }
    }
    static void readBrush(std::ifstream& genesisMap, GenesisBrush& brush) {
        BrushHeader brushH;
        genesisMap.read(reinterpret_cast<char*>(&brushH), sizeof(BrushHeader));

        brush.setFlags(brushH.flags);

        for (int i = 0; i < brushH.numFaces; ++i) {
            GenesisFace face;
            readFace(genesisMap, face);
            brush.insertFace(face);
        }
    }
    static void readFace(std::ifstream& genesisMap, GenesisFace& face) {
        FaceHeader faceH;
        genesisMap.read(reinterpret_cast<char*>(&faceH), sizeof(FaceHeader));

        face.setFlags(faceH.flags);
        face.setMipMapBias(faceH.mipMapBias);
        face.setLightIntensity(faceH.lightIntensity);
        face.setAlpha(faceH.alpha);
        face.setReflectivityScale(faceH.reflectivityScale);

        face.setTextureName(
            std::string(faceH.textureName, sizeof(faceH.textureName)));
        face.setVecU({faceH.uVecX, faceH.uVecY, faceH.uVecZ});
        face.setScaleX(faceH.xScale);
        face.setOffsetX(faceH.xOffset);

        face.setVecV({faceH.vVecX, faceH.vVecY, faceH.vVecZ});
        face.setScaleY(faceH.yScale);
        face.setOffsetY(faceH.yOffset);

        face.setNormal({faceH.normalX, faceH.normalY, faceH.normalZ});
        face.setDistance(faceH.distance);
    }

    static void readInt(std::ifstream& genesisMap, int& value) {
        genesisMap.read(reinterpret_cast<char*>(&value), sizeof(std::int32_t));
    }
    static std::string readString(std::ifstream& genesisMap) {
        int length;
        readInt(genesisMap, length);

        std::string str(length, '\0');
        genesisMap.read(&str[0], length);
        return str;
    }
};
