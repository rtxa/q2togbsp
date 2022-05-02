#pragma once

#include "GenesisBrush.h"

#include <map>
#include <string>
#include <vector>

class GenesisEntity {
public:
	GenesisEntity();
	void insertBrush(GenesisBrush brush);
	void insertKeyValue(std::string key, std::string value);
	int getNumKeys() const;
	int getNumBrushes() const;
	int getFlags() const;

	void setFlags(int flags);

	// Iterators
	inline std::vector<GenesisBrush>::const_iterator begin() const { return m_brushes.begin(); };
	inline std::vector<GenesisBrush>::const_iterator end() const { return m_brushes.end(); };
	
	inline std::map<std::string, std::string>::const_iterator beginKeyValues() const { return m_keyvalues.begin(); };
	inline std::map<std::string, std::string>::const_iterator endKeyValues() const { return m_keyvalues.end(); };

private:
	//bool hasMotion();
	std::vector<GenesisBrush> m_brushes;
	std::map<std::string, std::string> m_keyvalues;

	int m_flags;
	static constexpr int EntityModelMotion = (1<<0); // entity flag
};