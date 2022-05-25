#pragma once

#include "QuakeEntity.h"

#include <vector>
#include <string>

class QuakeMap {
public:
	void insertEntity(const QuakeEntity& entity);

	std::vector<QuakeEntity>& entities();
	const std::vector<QuakeEntity>& entities() const;

	std::string dump() const;
	
private:
	std::vector<QuakeEntity> m_entities;
};
