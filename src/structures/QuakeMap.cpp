#include "QuakeMap.h"
#include <iostream>

void QuakeMap::insertEntity(const QuakeEntity& entity) {
	m_entities.push_back(entity);
}

void QuakeMap::printAll() {
	int index = 0;
	for (auto itr = m_entities.begin(); itr != m_entities.end(); ++itr) {
		std::cout << "Printing Quake Entity: " << ++index << '\n';
		itr->printAll();
	}
}

std::vector<QuakeEntity>::const_iterator QuakeMap::begin() const {
	return m_entities.begin();
}

std::vector<QuakeEntity>::const_iterator QuakeMap::end() const {
	return m_entities.end();
}