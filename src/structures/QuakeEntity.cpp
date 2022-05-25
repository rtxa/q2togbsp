#include "QuakeEntity.h"

#include <iostream>

void QuakeEntity::insertKeyValue(const std::string& key, const std::string& value) {
	m_keyvalues.insert(std::pair<std::string, std::string>(key, value));
}

void QuakeEntity::insertBrush(const QuakeBrush& brush) {
	m_brushes.push_back(brush);
}

std::vector<QuakeBrush>& QuakeEntity::brushes() {
	return m_brushes;
}

const std::vector<QuakeBrush>& QuakeEntity::brushes() const {
	return m_brushes;
}

std::map<std::string, std::string>& QuakeEntity::properties() {
	return m_keyvalues;
}

const std::map<std::string, std::string>& QuakeEntity::properties() const {
	return m_keyvalues;
}
