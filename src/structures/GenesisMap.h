#pragma once

#include "GenesisBrush.h"
#include "GenesisEntity.h"

#include <vector>

class GenesisMap {
public:
	void insertEntity(GenesisEntity entity);
	int getNumEntities() const;
	void printAll();

	// Iterators
	inline std::vector<GenesisEntity>::const_iterator begin() const { return m_entities.begin(); };
	inline std::vector<GenesisEntity>::const_iterator end() const { return m_entities.end(); };

private:
	std::vector<GenesisEntity> m_entities;
};