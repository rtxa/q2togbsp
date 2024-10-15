#pragma once

#include <fstream>
#include <string>
#include <vector>

class StringTokenizer {
   public:
    StringTokenizer(const std::string& line);
    const std::vector<std::string>& tokens();
    std::string nextToken();
    float nextTokenFloat();
    int nextTokenInt();
    bool hasMoreTokens();
    size_t countTokens();

   private:
    std::vector<std::string> m_tokens;
};
