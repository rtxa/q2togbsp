#include "GenesisMap.h"

#include <iostream>
#include <sstream>

void GenesisMap::insertEntity(const GenesisEntity& entity) {
    m_entities.push_back(entity);
}

int GenesisMap::getNumEntities() const {
    return m_entities.size();
}

std::vector<GenesisEntity>& GenesisMap::entities() {
    return m_entities;
}

const std::vector<GenesisEntity>& GenesisMap::entities() const {
    return m_entities;
}

std::string GenesisMap::dump() const {
    std::stringstream stream;
    for (const auto& ent : m_entities) {
        int brushCount = 0;
        for (const auto& brush : ent.brushes()) {
            stream << "Brush Number: " << ++brushCount << '\n';
            for (const auto& face : brush.faces()) {
                stream << "  " << face.toString() << '\n';
            }
        }
    }
    return stream.str();
}