#pragma once

#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "fmt/format.h"

#include "typeparser/CTokenizer.h"

struct EntDefProp {
    EntDefProp()
        : isPublished(false),
          isOrigin(false),
          isAngles(false),
          isArc(false),
          isRadius(false) {}

    std::string type;
    std::string name;
    std::optional<std::string> defaultValue;
    std::optional<std::string> documentation;
    bool isPublished;
    bool isOrigin;
    bool isAngles;
    bool isRadius;
    bool isArc;
};

struct EntDef {
    std::string typeIcon;  // GE_Type
    std::string name;      // Entity classname
    std::vector<EntDefProp> properties;
};

enum class ParserState {
    None,
    FindStartOfStruct,
    FindStartBraceStruct,
    ParseStruct
};

class EntDefParser {
   public:
    /**
     * Parse a file and return a list of EntDef. The file must be a C header
     * file containing typedefs of structs with the following format:
     *
     *  typedef struct <name> {
     *      <data>
     *  } <name>;
     *
     *  The parser will extract the name of the entity, and each property of the
     *  entity. The properties will be extracted from the struct members.
     *
     *  The parser will also handle the GE_Type and GE_Published pragmas. The
     *  GE_Type will be used to determine the type icon of the entity, and the
     *  GE_Published will be used to determine which properties will be
     * published to the engine.
     *
     *  @param filename The file to parse
     *
     *  @return A list of EntDef
     *  @throws std::runtime_error if the file cannot be opened or parsing fails
     */
    static std::vector<EntDef> parse(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error(
                fmt::format("Could not open file: {}", filename));
        }

        std::vector<EntDef> ents;
        EntDef entDef;
        ParserState parserState = ParserState::None;
        std::string line;
        size_t numLine = 0;
        bool isPublished = false;

        auto tokenizerState = CTokenizerState::Normal;
        while (std::getline(file, line)) {
            numLine++;
            auto tokens = CTokenizer::tokenize(line, tokenizerState);

            // Handle comments
            if (tokenizerState == CTokenizerState::InMultiLineComment) {
                continue;
            }

            // Debug purposes
            // for (const auto& token : tokens) {
            //     std::cout << fmt::format("Token: {} Column: {} Line: {}\n",
            //                              token.value, token.column, numLine);
            // }

            if (tokens.empty()) {
                continue;
            }

            if (parserState == ParserState::None) {
                parserState = handlePragmaType(tokens, entDef, numLine);
            } else if (parserState == ParserState::FindStartOfStruct) {
                parserState = handleStructStart(tokens, entDef, numLine);
            } else if (parserState == ParserState::FindStartBraceStruct) {
                parserState = handleStartBraceStruct(tokens);
            } else if (parserState == ParserState::ParseStruct) {
                parserState =
                    handleStruct(tokens, entDef, isPublished, numLine);
                if (parserState == ParserState::None) {
                    ents.push_back(entDef);
                }
            }
        }

        // If we end parsing the file and the parser status is different from
        // none then something happened and we need to throw an error
        if (parserState == ParserState::FindStartBraceStruct) {
            throw std::runtime_error(
                fmt::format("Expected '{' in typedef struct <name> "
                            "at line {}",
                            numLine));
        }

        return ents;
    }

   private:
    static ParserState handleStructStart(const std::vector<CToken>& tokens,
                                         EntDef& entDef,
                                         size_t numLine) {
        if (tokens.size() < 3 ||
            (tokens[0].value != "typedef" || tokens[1].value != "struct")) {
            throw std::runtime_error(
                fmt::format("Expected 'typedef struct' when reading "
                            "entity definition at line {}",
                            numLine));
        }

        if (tokens.size() >= 4 && tokens[3].value == "{") {
            return ParserState::ParseStruct;
        } else {
            return ParserState::FindStartBraceStruct;
        }
    }

    static ParserState handleStartBraceStruct(
        const std::vector<CToken>& tokens) {
        if (!tokens.empty() && tokens[0].value == "{") {
            return ParserState::ParseStruct;
        }
        return ParserState::FindStartBraceStruct;  // Still waiting for brace
    }

    static ParserState handleStruct(std::vector<CToken>& tokens,
                                    EntDef& entDef,
                                    bool& isPublished,
                                    size_t numLine) {
        // Reading pragmas
        if (tokens.size() >= 2 && tokens[0].value == "#pragma") {
            if (tokens[1].value == "GE_Published") {
                isPublished = true;
            } else if (tokens[1].value == "GE_Private") {
                isPublished = false;
            } else if (tokens[1].value == "GE_DefaultValue") {
                handleSpecialField(entDef, tokens, numLine);
            } else if (tokens[1].value == "GE_Documentation") {
                handleSpecialField(entDef, tokens, numLine);
            } else if (tokens[1].value == "GE_Origin") {
                handleSpecialField(entDef, tokens, numLine);
            } else if (tokens[1].value == "GE_Angles") {
                handleSpecialField(entDef, tokens, numLine);
            } else if (tokens[1].value == "GE_Arc") {
                handleSpecialField(entDef, tokens, numLine);
            } else if (tokens[1].value == "GE_Radius") {
                handleSpecialField(entDef, tokens, numLine);
            }
            // If it's not our pragma, then skip it.
            return ParserState::ParseStruct;
        }
        // End of reading struct, gather name for the ent def
        if (tokens.size() >= 2 && tokens[0].value == "}") {
            entDef.name = tokens[1].value;
            isPublished = false;
            return ParserState::None;
        }

        // If type is a pointer like char*, then it's part of the
        // name
        if (tokens[1].value == "*") {
            tokens[0].value.append("*");
            tokens.erase(tokens.begin() + 1);
        }

        EntDefProp prop;
        prop.type = tokens[0].value;
        prop.name = tokens[1].value;
        prop.isPublished = isPublished;
        entDef.properties.push_back(prop);

        return ParserState::ParseStruct;
    }

    static void handleSpecialField(EntDef& entDef,
                                   const std::vector<CToken>& tokens,
                                   int numLine) {
        auto fieldName = tokens[1].value;
        auto propName = tokens[3].value;
        auto it =
            std::find_if(entDef.properties.begin(), entDef.properties.end(),
                         [&](const EntDefProp& property) {
                             return property.name == propName;
                         });

        if (it == entDef.properties.end()) {
            throw std::runtime_error(
                fmt::format("Property '{}' not found to set {} in "
                            "entity definition at line {}",
                            propName, fieldName, numLine));
        }

        if (fieldName == "GE_DefaultValue") {
            auto value = tokens[5].value;
            removeQuotes(value);
            it->defaultValue = value;
        } else if (fieldName == "GE_Documentation") {
            auto value = tokens[5].value;
            removeQuotes(value);
            it->documentation = value;
        } else if (fieldName == "GE_Origin") {
            it->isOrigin = true;
        } else if (fieldName == "GE_Angles") {
            it->isAngles = true;
        } else if (fieldName == "GE_Arc") {
            it->isArc = true;
        } else if (fieldName == "GE_Radius") {
            it->isRadius = true;
        }
    }

    static ParserState handlePragmaType(const std::vector<CToken>& tokens,
                                        EntDef& entDef,
                                        size_t numLine) {
        // Try to parse #pragma GE_Type("")
        if (tokens.size() >= 5) {
            if (tokens[0].value == "#pragma" && tokens[1].value == "GE_Type") {
                if (tokens[2].value != "(") {
                    throw std::runtime_error(
                        fmt::format("Expected '(' in #pragma "
                                    "GE_Type(...) at line {}, column {}",
                                    numLine, tokens[2].column));
                }

                if (tokens[4].value != ")") {
                    throw std::runtime_error(
                        fmt::format("Expected ')' in #pragma "
                                    "GE_Type(...) at line {}, column {}",
                                    numLine, tokens[4].column));
                }
                auto type = tokens[3].value;
                removeQuotes(type);
                entDef = EntDef();
                entDef.typeIcon = type;
                return ParserState::FindStartOfStruct;
            }
        }
        return ParserState::None;
    }

    /**
     * Removes double quotes from the given string at beggining and end.
     */
    static void removeQuotes(std::string& str) {
        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
    }
};
