#pragma once

#include <string>
#include <vector>
#include <map>

#include "QuakeBrush.h"

class QuakeEntity {
public:
	void insertBrush(QuakeBrush brush);
	void insertKeyValue(std::string key, std::string value);
	void printKeyValues();
	void printBrushes();
	void printAll();
	// Iterators
	inline std::vector<QuakeBrush>::const_iterator begin() const { return m_brushes.begin(); };
	inline std::vector<QuakeBrush>::const_iterator end() const { return m_brushes.end(); };
	
	inline std::map<std::string, std::string>::const_iterator beginKeyValues() const { return m_keyvalues.begin(); };
	inline std::map<std::string, std::string>::const_iterator endKeyValues() const { return m_keyvalues.end(); };
private:
	std::vector<QuakeBrush> m_brushes;
	std::map<std::string, std::string> m_keyvalues;
};

