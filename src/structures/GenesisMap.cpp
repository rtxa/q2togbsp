#include "GenesisMap.h"
#include <iostream>

void GenesisMap::insertEntity(const GenesisEntity& entity) {
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

std::vector<GenesisEntity>& GenesisMap::entities() {
	return m_entities;
}

const std::vector<GenesisEntity>& GenesisMap::entities() const {
	return m_entities;
}