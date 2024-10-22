#pragma once

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class CTokenizerState { Normal, InMultiLineComment };

struct CToken {
    std::string value;
    size_t column;
};

class CTokenizer {
   public:
    /**
     * Tokenize a C style line into individual tokens
     *
     * @param line The line to tokenize
     * @param state The state of the tokenizer
     *
     * @return A vector of tokens
     *
     */
    static std::vector<CToken> tokenize(const std::string& line,
                                        CTokenizerState& state) {
        std::vector<CToken> tokens;
        std::string token;
        bool inQuotes = false;
        bool inSingleLineComment = false;
        size_t column = 0;

        for (size_t i = 0; i < line.length(); i++) {
            char ch = line[i];
            column++;

            if (inSingleLineComment) {
                continue;
            }

            if (state == CTokenizerState::InMultiLineComment) {
                if (ch == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                    state = CTokenizerState::Normal;
                    i++;
                    column++;
                }
                continue;
            }

            if (ch == '"') {
                inQuotes = !inQuotes;
                if (inQuotes) {
                    token += ch;
                } else {
                    token += ch;
                    tokens.push_back(
                        CToken{token, column + 1 - token.length()});
                    token.clear();
                }
            } else if (ch == '/' && i + 1 < line.length()) {
                if (line[i + 1] == '/') {
                    inSingleLineComment = true;
                    continue;
                } else if (line[i + 1] == '*') {
                    state = CTokenizerState::InMultiLineComment;
                    continue;
                }
            } else if (inQuotes) {
                token += ch;
            } else if (isspace(static_cast<unsigned char>(ch)) ||
                       isDelimiter(ch) || isOperator(ch)) {
                if (!token.empty()) {
                    tokens.push_back(CToken{token, column - token.length()});
                    token.clear();
                }
                if (isDelimiter(ch) || isOperator(ch)) {
                    tokens.push_back(CToken{std::string(1, ch), column});
                }
            } else {
                token += ch;
            }
        }

        if (!token.empty()) {
            tokens.push_back(CToken{token, column + 1 - token.length()});
        }

        return tokens;
    }

   private:
    static bool isDelimiter(char ch) {
        return ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '{' ||
               ch == '}' || ch == '[' || ch == ']';
    }

    static bool isOperator(char ch) {
        return ch == '*' || ch == '&' || ch == '=';
    }
};
