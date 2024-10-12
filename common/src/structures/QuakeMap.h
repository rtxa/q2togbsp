#pragma once

#include "QuakeEntity.h"

#include <string>
#include <vector>

class QuakeMap {
   public:
    void insertEntity(const QuakeEntity& entity);

    std::vector<QuakeEntity>& entities();
    const std::vector<QuakeEntity>& entities() const;

    std::string dump() const;

   private:
    std::vector<QuakeEntity> m_entities;
};
