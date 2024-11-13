#include "GBSPWriter.h"
#include "typeparser/EntDef.h"

#include <iostream>

void GBSPWriter::writeGBSPFile(const std::string& filename,
                               const GenesisMap& gMap,
                               const std::vector<EntDef>& entDefs) {
    m_genesisMap.open(filename, std::ios::out | std::ios::binary);

    if (!m_genesisMap.is_open()) {
        throw std::runtime_error("Can't open file");
    }

    writeFileHeader(gMap, entDefs);

    for (const auto& ent : gMap.entities()) {
        writeEntity(ent);
    }

    if (entDefs.empty()) {
        writeFixedEntDefs();
    } else {
        // Write entity definitions starting from the end to match what Genesis
        // EntTypeDef writer does
        for (auto it = entDefs.rbegin(); it != entDefs.rend(); ++it) {
            writeEntDef(*it, entDefs);
        }
    }
}

bool GBSPWriter::writeFileHeader(const GenesisMap& gMap,
                                 const std::vector<EntDef>& entDefs) {
    // Sum of worldspawn entity + point entities + entities definitions;
    int num = gMap.getNumEntities() + entDefs.size();

    FileHeader f = {
        1,                     // version
        {'N', 'C', 'B', 'F'},  // tag (Non-coding binary file)
        num                    // num of entities
    };

    m_genesisMap.write(reinterpret_cast<const char*>(&f), sizeof(FileHeader));

    return true;
}

bool GBSPWriter::writeFace(const GenesisFace& face) {
    FaceHeader faceH;

    faceH.flags = face.getFlags();
    faceH.mipMapBias = face.getMipMapBias();
    faceH.lightIntensity = static_cast<float>(face.getLightIntensity());
    faceH.alpha = face.getAlpha();
    faceH.reflectivityScale = face.getReflectivityScale();

    memcpy(faceH.textureName, face.getTextureName().c_str(),
           sizeof(faceH.textureName));

    faceH.uVecX = face.getVecU().x;
    faceH.uVecY = face.getVecU().y;
    faceH.uVecZ = face.getVecU().z;

    faceH.xScale = face.getScaleX();
    faceH.xOffset = face.getOffsetX();

    faceH.vVecX = face.getVecV().x;
    faceH.vVecY = face.getVecV().y;
    faceH.vVecZ = face.getVecV().z;

    faceH.yScale = face.getScaleY();
    faceH.yOffset = face.getOffsetY();

    faceH.normalX = face.getNormal().x;
    faceH.normalY = face.getNormal().y;
    faceH.normalZ = face.getNormal().z;

    faceH.distance = face.getDistance();

    m_genesisMap.write(reinterpret_cast<const char*>(&faceH),
                       sizeof(FaceHeader));

    return true;
}

bool GBSPWriter::writeKeyValue(const std::string& key,
                               const std::string& value) {
    writeString(key);
    writeString(value);
    return true;
}

bool GBSPWriter::writeEntity(const GenesisEntity& gEnt) {
    writeInt(gEnt.getNumBrushes());
    if (gEnt.getNumBrushes() > 0) {
        for (const auto& brush : gEnt.brushes()) {
            writeBrush(brush);
        }
    }

    writeInt(gEnt.getFlags());
    writeInt(gEnt.getNumKeys());

    for (const auto& property : gEnt.properties()) {
        writeKeyValue(property.first, property.second);
    }

    return true;
}

bool GBSPWriter::writeBrush(const GenesisBrush& brush) {
    BrushHeader brushH;
    brushH.flags = brush.getFlags();
    brushH.numFaces = brush.getNumFaces();

    m_genesisMap.write(reinterpret_cast<const char*>(&brushH),
                       sizeof(BrushHeader));

    for (const auto& face : brush.faces()) {
        writeFace(face);
    }

    return true;
}

/**
 * @brief Writes the fixed entity definitions to the Genesis map file.
 *
 * Fixed entity definitions are special entities that are always
 * present in a map, and have no brushes attached to them. They
 * are used to define the default values for certain keyvalues
 * that are used by other entities in the map.
 *
 * This function writes two fixed entity definitions to the
 * map file: "DeathMatchStart" and "light". The "DeathMatchStart"
 * entity has no special properties, while the "light" entity
 * has properties for light color, style, and origin.
 *
 * This is useful for maps that don't provide any entity definitions.
 */
void GBSPWriter::writeFixedEntDefs() {
    // No brushes attached to this entity
    int numBrushes = 0;
    int entFlags = 0;   // no motion for this entity
    int numFields = 4;  // numfields = classname + name + origin

    writeInt(numBrushes);
    writeInt(entFlags);
    writeInt(numFields);

    // Keyvalues
    writeKeyValue("classname", "%typedef%");
    writeKeyValue("%typename%", "DeathMatchStart");
    writeKeyValue("Origin", "point");
    writeKeyValue("%defaultvalue%", "");

    // No brushes attached to this entity
    numBrushes = 0;
    entFlags = 0;    // no motion for this entity
    numFields = 10;  // numfields = classname + name + origin

    writeInt(numBrushes);
    writeInt(entFlags);
    writeInt(numFields);

    // Keyvalues
    writeKeyValue("classname", "%typedef%");
    writeKeyValue("%typename%", "light");
    writeKeyValue("light", "int");
    writeKeyValue("%defaultvalue%", "");
    writeKeyValue("color", "color");
    writeKeyValue("%defaultvalue%", "");
    writeKeyValue("style", "int");
    writeKeyValue("%defaultvalue%", "");
    writeKeyValue("Origin", "point");
    writeKeyValue("%defaultvalue%", "");
}

std::string removeTrailingAsterisk(std::string str) {
    if (!str.empty() && str.back() == '*') {
        str.erase(str.size() - 1);
    }
    return str;
}

bool hasTrailingAsterisk(const std::string& str) {
    return !str.empty() && str.back() == '*';
}

/**
 * @brief Converts a type extracted from a C header (user entity
 *        definition) to what Genesis3D understands in binary map files.
 *
 * @param[in] type Type string extracted from a C header.
 * @return Type string that Genesis3D understands in its binary map files.
 */
std::string convertTypeToGBSP(const std::string& type,
                              bool isPublished,
                              const std::vector<EntDef>& entDefs) {
    // Convert types extracted from C header with user entity definition
    // to what genesis3d understands in binary map files

    if (type == "int" || type == "geBoolean") {
        return "int";
    } else if (type == "GE_RGBA") {
        return "color";
    } else if (type == "geFloat" || type == "float") {
        return "float";
    } else if (type == "geWorld_Model*") {
        return "model";
    } else if (type == "geVec3d") {
        return "point";
    } else if (type == "char*") {
        return "string";
    } else if (!isPublished) {
        if (hasTrailingAsterisk(type)) {
            auto strippedType = removeTrailingAsterisk(type);
            auto it = std::find_if(entDefs.begin(), entDefs.end(),
                                   [&](const EntDef property) {
                                       return property.name == strippedType;
                                   });

            if (it != entDefs.end()) {
                return strippedType;
            }
        }
        return "ptr";

    } else {
        return removeTrailingAsterisk(type);
    }
}

void GBSPWriter::writeEntDef(const EntDef& entDef,
                             const std::vector<EntDef>& entDefs) {
    int numBrushes = 0;  // No brushes attached to this entity
    int entFlags = 0;    // No motion for this entity

    // Adjust for default value pairs and classname and %typename% fields
    int numFields = (entDef.properties.size() * 2) + 2;

    writeInt(numBrushes);
    writeInt(entFlags);
    writeInt(numFields);

    // Keyvalues
    writeKeyValue("classname", "%typedef%");
    writeKeyValue("%typename%", entDef.name);

    for (const auto& prop : entDef.properties) {
        writeKeyValue(prop.name,
                      convertTypeToGBSP(prop.type, prop.isPublished, entDefs));
        writeKeyValue("%defaultvalue%", "");  // I don't get why is empty...
    }
}

void GBSPWriter::writeInt(int value) {
    m_genesisMap.write(reinterpret_cast<const char*>(&value),
                       sizeof(std::int32_t));
}

void GBSPWriter::writeString(const std::string& str) {
    int length = str.length();
    m_genesisMap.write(reinterpret_cast<const char*>(&length),
                       sizeof(std::int32_t));
    m_genesisMap.write(reinterpret_cast<const char*>(str.c_str()),
                       str.length());
}
