#include "QuakeMap.h"

#include <fmt/format.h>

#include <iostream>
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
			stream << fmt::format("\"{}\" \"{}\"\n", property.first, property.second);
		}

		int brushCount = 0;
      	for (const auto& brush : ent.brushes()) {
			stream << "Brush number: " << ++brushCount << '\n';
			for (const auto& face : brush.faces()) {
				stream << fmt::format("Face: ( {} ) ( {} ) ( {} ) ", 
									  face.getPlane(0).toString(), 
									  face.getPlane(1).toString(), 
									  face.getPlane(2).toString());
																	
				stream << fmt::format("TexName: {} Scale X/Y: {} {} Offset X/Y: {} {} Rotation: {}\n",
						              face.getTextureName(), face.getScaleX(), face.getScaleY(), 
									  face.getOffsetX(), face.getOffsetY(), face.getRotation());
			}
		}
    }

	return stream.str();
}