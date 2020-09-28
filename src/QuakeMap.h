#pragma once

#include <vector>
#include "QuakeEntity.h"

class QuakeMap {
public:
	void insertEntity(QuakeEntity entity);
	void printAll();
	std::vector<QuakeEntity>::const_iterator begin() const;
	std::vector<QuakeEntity>::const_iterator end() const;
private:
	std::vector<QuakeEntity> m_entities;
};
