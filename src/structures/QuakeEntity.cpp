#include "QuakeEntity.h"

#include <iostream>

void QuakeEntity::insertKeyValue(const std::string& key, const std::string& value) {
	m_keyvalues.insert(std::pair<std::string, std::string>(key, value));
}

void QuakeEntity::printKeyValues() const {
	for (const auto& property : m_keyvalues) {
		std::cout << '\t' << property.first << '\t' << property.second << '\n';
	}
}

void QuakeEntity::printBrushes() const {
	int index = 0;
	for (const auto& brush : m_brushes) {
		std::cout << "Brush number " << ++index << '\n';
		brush.printFaces();
	}
}

void QuakeEntity::printAll() const {
	printKeyValues();
	printBrushes();
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
