#pragma once

#include <vector>
#include <string>
#include <fstream>

class StringTokenizer {
public:
	StringTokenizer() {};
	StringTokenizer(const std::string line);
	std::string nextToken();
	float nextTokenFloat();
	bool hasMoreTokens();
	int countTokens();
private:
	std::vector<std::string> m_tokens;
	std::string m_token;
};

