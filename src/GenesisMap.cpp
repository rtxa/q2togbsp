#include "GenesisMap.h"
#include <iostream>

void GenesisMap::insertBrush(const GenesisBrush brush) {
	m_worldspawn.push_back(brush);
}

void GenesisMap::insertEntity(const GenesisEntity entity) {
	m_entities.push_back(entity);
}

int GenesisMap::getNumBrushes() const {
	return m_worldspawn.size();
}

int GenesisMap::getNumEntities() const {
	return m_entities.size();
}

void GenesisMap::printAll() {
	int index = 0;
   	for (auto itr = m_worldspawn.begin(); itr != m_worldspawn.end(); ++itr) {
		std::cout << "Printing Genesis Brush: " << ++index << '\n';
		itr->printBrush();
	}
 
}
