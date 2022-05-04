#include "QuakeEntity.h"

#include <iostream>

void QuakeEntity::insertKeyValue(std::string key, std::string value) {
	m_keyvalues.insert(std::pair<std::string, std::string>(key, value));
}

void QuakeEntity::printKeyValues() {
	for (auto itr = m_keyvalues.begin(); itr != m_keyvalues.end(); itr++) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
}

void QuakeEntity::printBrushes() {
	int index = 0;
	for (auto itr = m_brushes.begin(); itr != m_brushes.end(); itr++) {
		std::cout << "Brush number " << ++index << '\n'; // overflow issues
		itr->printFaces();
	}
}

void QuakeEntity::printAll() {
	printKeyValues();
	printBrushes();
}

void QuakeEntity::insertBrush(QuakeBrush brush) {
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
