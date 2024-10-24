#pragma once

#include "GenesisEntity.h"

#include <vector>

class GenesisMap {
   public:
    void insertEntity(const GenesisEntity& entity);
    int getNumEntities() const;

    std::vector<GenesisEntity>& entities();
    const std::vector<GenesisEntity>& entities() const;

    std::string dump() const;

   private:
    std::vector<GenesisEntity> m_entities;
};