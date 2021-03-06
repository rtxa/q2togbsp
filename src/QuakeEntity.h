#pragma once

#include <string>
#include <vector>
#include <map>

#include "QuakeBrush.h"

class QuakeEntity {
public:
	void insertBrush(const QuakeBrush brush);
	void insertKeyValue(const std::string key, const std::string value);
	void printKeyValues();
	void printBrushes();
	void printAll();
	// Iterators
	inline std::vector<QuakeBrush>::const_iterator QuakeEntity::begin() const { return m_brushes.begin(); };
	inline std::vector<QuakeBrush>::const_iterator QuakeEntity::end() const { return m_brushes.end(); };
	
	inline std::map<std::string, std::string>::const_iterator QuakeEntity::beginKeyValues() const { return m_keyvalues.begin(); };
	inline std::map<std::string, std::string>::const_iterator QuakeEntity::endKeyValues() const { return m_keyvalues.end(); };
private:
	std::vector<QuakeBrush> m_brushes;
	std::map<std::string, std::string> m_keyvalues;
};

