#include "StringTokenizer.h"

#include <iomanip>
#include <iostream>
#include <sstream>

StringTokenizer::StringTokenizer(const std::string& line) {
	std::stringstream linestream(line);
	std::string token;

	// separates by whitespaces and ignores quotes
	while (linestream >> std::quoted(token)) {
		m_tokens.insert(m_tokens.begin(), token);
	}
}

std::string StringTokenizer::nextToken() {
	if (m_tokens.empty()) {
		return "";
	}

	std::string token = m_tokens.back();
	m_tokens.pop_back();

	return token;
}

float StringTokenizer::nextTokenFloat() {
	return std::stof(nextToken());
}

int StringTokenizer::nextTokenInt() {
	return std::stoi(nextToken());
}

bool StringTokenizer::hasMoreTokens() {
	return !m_tokens.empty();
}

size_t StringTokenizer::countTokens() {
	return m_tokens.size();
}

/*
 * Get a copy of the list of tokens from this tokenizer
 */
std::vector<std::string> StringTokenizer::getTokensList() {
	return m_tokens;
}