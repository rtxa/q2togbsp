#include "GenesisMap.h"
#include <iostream>

void GenesisMap::insertEntity(const GenesisEntity entity) {
	m_entities.push_back(entity);
}

int GenesisMap::getNumEntities() const {
	return m_entities.size();
}

void GenesisMap::printAll() {
	for (auto itrEnt = m_entities.begin(); itrEnt != m_entities.end(); itrEnt++) {
		int index = 0;
		for (auto itrBrush = itrEnt->begin(); itrBrush != itrEnt->end(); itrBrush++) {
			std::cout << "Printing Genesis Brush: " << ++index << '\n';
			itrBrush->printBrush();
		}
	}
}
