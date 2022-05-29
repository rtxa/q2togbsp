#include "QuakeMap.h"

#include <iostream>
#include <iomanip>
#include <sstream>

void QuakeMap::insertEntity(const QuakeEntity& entity) {
	m_entities.push_back(entity);
}

std::vector<QuakeEntity>& QuakeMap::entities() {
	return m_entities;
}

const std::vector<QuakeEntity>& QuakeMap::entities() const {
	return m_entities;
}

std::string QuakeMap::dump() const {
	std::stringstream stream;
	int entCount = 0;

    for (const auto& ent : entities()) {
		stream << "Entity number: " << ++entCount << '\n';
		
		for (const auto& property : ent.properties()) {
			stream << "  " << std::quoted(property.first) << ' ' << std::quoted(property.second) << '\n';
		}

		int brushCount = 0;
      	for (const auto& brush : ent.brushes()) {
			stream << "Brush number: " << ++brushCount << '\n';
			for (const auto& face : brush.faces()) {
				stream << "  " << face.toString() << '\n';
			}
		}
    }

	return stream.str();
}