#pragma once
#include <stdexcept>

// Types of errors
// Categories:
// - Eof: unexpected end of the input data
// EofWhileParsingBrush
// EofWhileParsingEntity
// - Syntax:
// ExpectedSomeIdent

// QuakeParserError::
// namespace::error

enum class QuakeParserError {
    // IO: failure to read or write bytes on an IO stream
    FileEmpty,
    FileNotOpen,
    // EOF: unexpected end of the input data
    EofWhileParsingEntity,
    EofWhileParsingBrush,
    EofWhileParsingBrushFace,
    // Syntax: input that is not syntactically valid
    ExpectedOpenBrace,
    ExpectedCloseBrace,
    ExpectedOpenParen,
    ExpectedCloseParen,
    // Data: input data that is semantically incorrect
    ExpectedInt,
    ExpectedFloat,
    NotEnoughFaces,
    NotEnoughPoints,
    NumberOutOfRange,
    NotEnoughTokens,
    NotEnoughTokensBrushFace,
    NotEnoughTokensPlane,
    NotEnoughTokensVector,
    VectorValueOutOfRange,
    VectorValueInvalid,
    UnexpectedTokenBrushFace,
    UnexpectedOpenBrace,
    UnexpectedCloseBrace,
    NoEntitiesFound,
    OtherError,
};

/**
 * @brief Contains a detailed description of the error with
 *        the last line/column.
 */
class QuakeParserException : public std::exception {
   public:
    QuakeParserException(QuakeParserError error)
        : m_error(error), m_line(0), m_column(0) {};
    QuakeParserException(QuakeParserError error, int line)
        : m_error(error), m_line(line), m_column(0) {};
    QuakeParserException(QuakeParserError error, int line, int column)
        : m_error(error), m_line(line), m_column(column) {};

    // int line();
    // int column();

    const char* what() const noexcept override;
    // "Error({:?}, line: {}, column: {})",
    // Un enum con todos los tipos de errors
   private:
    QuakeParserError m_error;
    int m_line;
    int m_column;
};