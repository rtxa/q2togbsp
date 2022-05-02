#pragma once

#include <fstream>
#include <string>
#include <vector>

class StringTokenizer {
public:
	StringTokenizer() {};
	StringTokenizer(std::string line);
	std::vector<std::string> getTokensList();
	std::string nextToken();
	float nextTokenFloat();
	int nextTokenInt();
	bool hasMoreTokens();
	int countTokens();
private:
	std::vector<std::string> m_tokens;
};

