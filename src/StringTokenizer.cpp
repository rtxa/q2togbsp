#include "StringTokenizer.h"
#include <iostream>
#include <sstream>
#include <iomanip>

StringTokenizer::StringTokenizer(std::string line) {
	std::stringstream linestream(line);
	std::string token;

	// separates by whitespaces and ignores quotes
	while (linestream >> std::quoted(token)) {
		m_tokens.insert(m_tokens.begin(), token);
	}
}

//std::string StringTokenizer::getToken() {	
//	return m_token;
//}

std::string StringTokenizer::nextToken() {
	if (m_tokens.empty()) {
		return "";
	}

	std::string token = m_tokens.back();
	m_tokens.pop_back();

	return token;
}

float StringTokenizer::nextTokenFloat() {
	std::string token = nextToken();
	float num = 0.0f;

	num = std::stof(token);

	return num;
}

bool StringTokenizer::hasMoreTokens() {
	return m_tokens.empty() ? false : true;
}

int StringTokenizer::countTokens() {
	return m_tokens.size();
}