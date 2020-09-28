#include "GenesisEntity.h"

GenesisEntity::GenesisEntity() {
	m_flags = 0;
}

void GenesisEntity::insertKeyValue(const std::string key, const std::string value) {
	m_keyvalues.insert(std::pair<std::string, std::string>(key, value));
}

int GenesisEntity::getNumKeys() {
	return m_keyvalues.size();
}

int GenesisEntity::getNumBrushes() {
	return m_brushes.size();
}

int GenesisEntity::getFlags() {
	return m_flags;
}

void GenesisEntity::setFlags(int flags) {
	m_flags = flags;
}


