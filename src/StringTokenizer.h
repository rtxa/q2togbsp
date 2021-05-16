#pragma once

#include <vector>
#include <string>
#include <fstream>

class StringTokenizer {
public:
	StringTokenizer() {};
	StringTokenizer(std::string line);
	std::vector<std::string> getTokensList();
	std::string nextToken();
	float nextTokenFloat();
	bool hasMoreTokens();
	int countTokens();
private:
	std::vector<std::string> m_tokens;
	std::string m_token;
};

