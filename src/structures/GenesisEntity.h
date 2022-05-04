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

	std::vector<GenesisBrush>& brushes();
	const std::vector<GenesisBrush>& brushes() const;
	
	std::map<std::string, std::string>& properties();
	const std::map<std::string, std::string>& properties() const;
	
private:
	//bool hasMotion();
	std::vector<GenesisBrush> m_brushes;
	std::map<std::string, std::string> m_keyvalues;

	int m_flags;
	static constexpr int EntityModelMotion = (1<<0); // entity flag
};