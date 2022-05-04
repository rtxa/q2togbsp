#include "GenesisEntity.h"

GenesisEntity::GenesisEntity() {
	m_flags = 0;
}

void GenesisEntity::insertBrush(GenesisBrush brush) {
	m_brushes.push_back(brush);
}

void GenesisEntity::insertKeyValue(std::string key, std::string value) {
	m_keyvalues.insert(std::pair<std::string, std::string>(key, value));
}

std::vector<GenesisBrush>& GenesisEntity::brushes() {
	return m_brushes;
}

const std::vector<GenesisBrush>& GenesisEntity::brushes() const {
	return m_brushes;
}

std::map<std::string, std::string>& GenesisEntity::properties() {
	return m_keyvalues;
}

const std::map<std::string, std::string>& GenesisEntity::properties() const {
	return m_keyvalues;
}

int GenesisEntity::getNumKeys() const {
	return m_keyvalues.size();
}

int GenesisEntity::getNumBrushes() const {
	return m_brushes.size();
}

int GenesisEntity::getFlags() const {
	return m_flags;
}

void GenesisEntity::setFlags(int flags) {
	m_flags = flags;
}


