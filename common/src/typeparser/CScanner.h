#pragma once

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum CTokenFlags {
    None = 0,
    StartOfLine = 1 << 0,   // Check if token was on a new line
    LeadingSpace = 2 << 0,  // Check if previous token is whitespace
};

enum class CTokenType { Eol, Eof, Word, StringLiteral };

enum class CScannerState {
    Normal,
    InSingleLineComment,
    InMultiLineComment,
    InQuotes
};

class CToken {
   public:
    std::string value;
    size_t numColumn;
    size_t numLine;
    int flags;
    CTokenType type;
};

class CScanner {
   private:
    CScannerState m_state{CScannerState::Normal};
    bool m_skipEol{true};
    std::vector<CToken> m_tokens;
    std::ifstream& m_file;
    std::size_t m_numLine{1};
    std::size_t m_numColumn{0};

   public:
    CScanner(std::ifstream& file) : m_file(file) {
        if (!m_file.is_open()) {
            throw std::runtime_error("File not open");
        }
    }

    CToken scanExpecting(std::string value) {
        auto token = nextToken();
        if (token.value != value) {
            throw std::runtime_error(
                fmt::format("Expected '{}', got '{}' at line {}, column {}",
                            value, token.value));
        }
        return token;
    }

    CToken nextToken() {
        if (!m_tokens.empty()) {
            auto token = m_tokens.front();
            m_tokens.erase(m_tokens.begin());
            return token;
        }

        std::string line;
        // Read the next line from the file
        while (std::getline(m_file, line)) {
            // If we reach here, we are at EOF or no tokens could be generated
            m_tokens = tokenize(line);
            m_numLine++;

            // Set the StartOfLine flag for the first token
            if (!m_tokens.empty()) {
                m_tokens[0].flags |= CTokenFlags::StartOfLine;
            }

            if (!m_tokens.empty()) {
                auto token = m_tokens.front();
                m_tokens.erase(m_tokens.begin());
                return token;
            }
        }

        // If we reach here, we are at EOF or no tokens could be generated
        if (m_file.eof()) {
            return CToken{"EOF", m_numColumn, m_numLine, CTokenFlags::None,
                          CTokenType::Eof};
        }

        throw std::runtime_error("No tokens could be generated");
    }

    /**
     * Tokenize a C style line into individual tokens
     *
     * @param line The line to tokenize
     *
     * @return A vector of tokens
     *
     */
    std::vector<CToken> tokenize(const std::string& line) {
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

            if (m_state == CScannerState::InMultiLineComment) {
                if (ch == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                    m_state = CScannerState::Normal;
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
                    tokens.push_back(CToken{token, column + 1 - token.length(),
                                            m_numLine, CTokenFlags::None,
                                            CTokenType::Word});
                    token.clear();
                }
            } else if (ch == '/' && i + 1 < line.length()) {
                if (line[i + 1] == '/') {
                    inSingleLineComment = true;
                    continue;
                } else if (line[i + 1] == '*') {
                    m_state = CScannerState::InMultiLineComment;
                    continue;
                }
            } else if (inQuotes) {
                token += ch;
            } else if (isspace(static_cast<unsigned char>(ch)) ||
                       isDelimiter(ch) || isOperator(ch)) {
                if (!token.empty()) {
                    tokens.push_back(CToken{token, column - token.length(),
                                            m_numLine, CTokenFlags::None,
                                            CTokenType::Word});
                    token.clear();
                }
                if (isDelimiter(ch) || isOperator(ch)) {
                    tokens.push_back(CToken{std::string(1, ch), column,
                                            m_numLine, CTokenFlags::None,
                                            CTokenType::Word});
                }
            } else {
                token += ch;
            }
        }

        if (!token.empty()) {
            tokens.push_back(CToken{token, column + 1 - token.length(),
                                    m_numLine, CTokenFlags::None,
                                    CTokenType::Word});
        }

        return tokens;
    }
    std::size_t getNumLines() const { return m_numLine; }
    void eolIsSignificant(bool flag) { m_skipEol = flag; }

   private:
    static bool isDelimiter(char ch) {
        return ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '{' ||
               ch == '}' || ch == '[' || ch == ']';
    }

    static bool isOperator(char ch) {
        return ch == '*' || ch == '&' || ch == '=';
    }
};
