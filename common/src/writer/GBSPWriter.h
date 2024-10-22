#pragma once

#include "structures/GenesisMap.h"
#include "typeparser/EntDef.h"

#include <fstream>
#include <iostream>
#include <vector>

class GBSPWriter {
#pragma pack(1)
    struct FileHeader {
        std::int32_t version;
        char tag[4];
        std::int32_t numEntities;
    };

    struct BrushHeader {
        std::int32_t flags;
        std::int32_t numFaces;
    };

    struct FaceHeader {
        std::int32_t flags;
        float mipMapBias;
        float alpha;           // Alpha for brush (0-255)
        float lightIntensity;  // face light
        float reflectivityScale;
        char textureName[32];
        float uVecX, uVecY, uVecZ;
        float xScale, xOffset;
        float vVecX, vVecY, vVecZ;
        float yScale, yOffset;
        float normalX, normalY, normalZ;
        float distance;
    };
#pragma pack()

   public:
    void writeGBSPFile(const std::string& filename,
                       const GenesisMap& gMap,
                       const std::vector<EntDef>& entDefs);

   private:
    std::fstream m_genesisMap;

    bool writeFileHeader(const GenesisMap& gMap,
                         const std::vector<EntDef>& entDefs);
    bool writeBrush(const GenesisBrush& brush);
    bool writeFace(const GenesisFace& face);
    bool writeKeyValue(const std::string& key, const std::string& value);
    bool writeEntity(const GenesisEntity& gEnt);

    // hardcoded
    void writeFixedEntDefs();
    void writeEntDef(const EntDef& entDef, const std::vector<EntDef>& entDefs);

    // Methods to write basic types in binary
    void writeInt(int value);
    void writeString(const std::string& str);
    // void writeBlock();
};