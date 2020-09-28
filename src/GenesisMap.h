#pragma once

#include <vector>
#include "GenesisBrush.h"
#include "GenesisEntity.h"

class GenesisMap {
public:
	void insertBrush(const GenesisBrush brush);
	void insertEntity(const GenesisEntity entity);
	int getNumBrushes() const;
	int getNumEntities() const;
	void printAll();

	// Iterators
	inline std::vector<GenesisBrush>::const_iterator GenesisMap::begin() const { return m_worldspawn.begin(); };
	inline std::vector<GenesisBrush>::const_iterator GenesisMap::end() const { return m_worldspawn.end(); };

	inline std::vector<GenesisEntity>::const_iterator GenesisMap::beginEnt() const { return m_entities.begin(); };
	inline std::vector<GenesisEntity>::const_iterator GenesisMap::endEnt() const { return m_entities.end(); };

private:
	std::vector<GenesisBrush> m_worldspawn;
	std::vector<GenesisEntity> m_entities;
};