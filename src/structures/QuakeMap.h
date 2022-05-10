#pragma once

#include "QuakeEntity.h"

#include <vector>

class QuakeMap {
public:
	void insertEntity(const QuakeEntity& entity);
	void printAll();

	std::vector<QuakeEntity>& entities();
	const std::vector<QuakeEntity>& entities() const;
private:
	std::vector<QuakeEntity> m_entities;
};
