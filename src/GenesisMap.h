#pragma once

#include <vector>
#include "GenesisBrush.h"
#include "GenesisEntity.h"

class GenesisMap {
public:
	void insertEntity(const GenesisEntity entity);
	int getNumEntities() const;
	void printAll();

	// Iterators
	inline std::vector<GenesisEntity>::const_iterator GenesisMap::beginEnt() const { return m_entities.begin(); };
	inline std::vector<GenesisEntity>::const_iterator GenesisMap::endEnt() const { return m_entities.end(); };

private:
	std::vector<GenesisEntity> m_entities;
};