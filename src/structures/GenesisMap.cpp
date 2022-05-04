#include "GenesisMap.h"
#include <iostream>

void GenesisMap::insertEntity(GenesisEntity entity) {
	m_entities.push_back(entity);
}

int GenesisMap::getNumEntities() const {
	return m_entities.size();
}

void GenesisMap::printAll() {
	for (const auto& ent : m_entities) {
		int index = 0;
		for (const auto& brush : ent.brushes()) {
			std::cout << "Printing Genesis Brush: " << ++index << '\n';
			brush.printBrush();
		}
	}
}
