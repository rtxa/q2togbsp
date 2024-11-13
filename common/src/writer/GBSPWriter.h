#pragma once

#include "structures/GenesisMap.h"
#include "typeparser/EntDef.h"
#include "writer/GBSPMap.h"

#include <fstream>
#include <iostream>
#include <vector>

class GBSPWriter {
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