#pragma once

#include "QuakeEntity.h"

#include <vector>

class QuakeMap {
public:
	void insertEntity(const QuakeEntity& entity);
	void printAll();
	std::vector<QuakeEntity>::const_iterator begin() const;
	std::vector<QuakeEntity>::const_iterator end() const;
private:
	std::vector<QuakeEntity> m_entities;
};
