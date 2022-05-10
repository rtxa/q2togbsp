#include "QuakeMap.h"
#include <iostream>

void QuakeMap::insertEntity(const QuakeEntity& entity) {
	m_entities.push_back(entity);
}

void QuakeMap::printAll() {
	int index = 0;
	for (const auto& ent : m_entities) {
		std::cout << "Printing Quake Entity: " << ++index << '\n';
		ent.printAll();
	}
}

std::vector<QuakeEntity>& QuakeMap::entities() {
	return m_entities;
}

const std::vector<QuakeEntity>& QuakeMap::entities() const {
	return m_entities;
}