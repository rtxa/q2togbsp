#pragma once

#include <string>
#include <vector>
#include <map>

#include "GenesisBrush.h"

class GenesisEntity {
public:
	GenesisEntity();
	void insertKeyValue(const std::string key, const std::string value);
	int getNumKeys();
	int getNumBrushes();
	int getFlags();

	void setFlags(int flags);

	// Iterators
	inline std::vector<GenesisBrush>::const_iterator GenesisEntity::begin() const { return m_brushes.begin(); };
	inline std::vector<GenesisBrush>::const_iterator GenesisEntity::end() const { return m_brushes.end(); };
	
	inline std::map<std::string, std::string>::const_iterator GenesisEntity::beginKeyValues() const { return m_keyvalues.begin(); };
	inline std::map<std::string, std::string>::const_iterator GenesisEntity::endKeyValues() const { return m_keyvalues.end(); };

private:
	//bool hasMotion();
	std::vector<GenesisBrush> m_brushes;
	std::map<std::string, std::string> m_keyvalues;

	int m_flags;
	static constexpr int EntityModelMotion = (1<<0); // entity flag
};