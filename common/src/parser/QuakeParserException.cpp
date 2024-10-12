#include "QuakeParserException.h"

#include <string>

const char* QuakeParserException::what() const noexcept {
    switch (m_error) {
        case QuakeParserError::EofWhileParsingBrush:
            return "EOF while parsing brush";
        case QuakeParserError::EofWhileParsingEntity:
            return "EOF while parsing entity";
        case QuakeParserError::ExpectedOpenBrace:
            return "expected {";
        case QuakeParserError::ExpectedCloseBrace:
            return "expected }";
        case QuakeParserError::ExpectedOpenParen:
            return "expected (";
        case QuakeParserError::ExpectedCloseParen:
            return "expected )";
        case QuakeParserError::NotEnoughTokens:
            return "not enough tokens";
        default:
            return "Unknown";
    }
}
