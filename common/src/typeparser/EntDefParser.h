#pragma once

#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "fmt/format.h"

#include "typeparser/CTokenizer.h"

struct Property {
    Property()
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
    std::vector<Property> properties;
};

enum class ParserStatus {
    None,
    FindStartOfStruct,
    FindStartBraceStruct,
    ParseStruct
};

class EntDefParser {
   public:
    std::vector<EntDef> ents;

    void parse(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Could not open file: " << filename << std::endl;
            return;
        }

        EntDef entDef;
        ParserStatus status = ParserStatus::None;
        std::string line;
        size_t numLine = 0;
        bool isPublished = false;

        auto state = CTokenizerState::Normal;
        while (std::getline(file, line)) {
            numLine++;
            auto tokens = CTokenizer::tokenize(line, state);

            // Handle comments
            if (state == CTokenizerState::InMultiLineComment) {
                continue;
            }

            // Debug purposes
            for (const auto& token : tokens) {
                std::cout << fmt::format("Token: {} Column: {} Line: {}\n",
                                         token.value, token.column, numLine);
            }

            if (tokens.empty()) {
                continue;
            }

            if (status == ParserStatus::None) {
                // Try to parse #pragma GE_Type("")
                if (tokens.size() >= 5) {
                    if (tokens[0].value == "#pragma" &&
                        tokens[1].value == "GE_Type") {
                        if (tokens[2].value != "(") {
                            throw std::runtime_error(
                                fmt::format("Expected '(' in #pragma "
                                            "GE_Type(...) at line {}",
                                            numLine));
                        }

                        if (tokens[4].value != ")") {
                            throw std::runtime_error(
                                fmt::format("Expected ')' in #pragma "
                                            "GE_Type(...) at line {}",
                                            numLine));
                        }
                        auto type = tokens[3].value;
                        removeQuotes(type);
                        entDef = EntDef();
                        entDef.typeIcon = type;
                        status = ParserStatus::FindStartOfStruct;
                    }
                }
            } else if (status == ParserStatus::FindStartOfStruct) {
                if (tokens.size() < 3 || (tokens[0].value != "typedef" ||
                                          tokens[1].value != "struct")) {
                    throw std::runtime_error(
                        fmt::format("Expected 'typedef struct' when reading "
                                    "entity definition at line {}",
                                    numLine));
                }

                if (tokens.size() >= 4 && tokens[3].value == "{") {
                    status = ParserStatus::ParseStruct;
                } else {
                    status = ParserStatus::FindStartBraceStruct;
                }

            } else if (status == ParserStatus::FindStartBraceStruct) {
                if (tokens.size() > 0 && tokens[0].value == "{") {
                    status = ParserStatus::ParseStruct;
                } else {
                    // Still waiting for the brace
                    continue;
                }
            } else if (status == ParserStatus::ParseStruct) {
                // Reading pragmas
                if (tokens.size() >= 2 && tokens[0].value == "#pragma") {
                    if (tokens[1].value == "GE_Published") {
                        isPublished = true;
                    } else if (tokens[1].value == "GE_Private") {
                        isPublished = false;
                    } else if (tokens[1].value == "GE_DefaultValue") {
                        auto propName = tokens[3].value;
                        auto defaultValue = tokens[5].value;
                        removeQuotes(defaultValue);
                        auto it = std::find_if(
                            entDef.properties.begin(), entDef.properties.end(),
                            [&](const Property& property) {
                                return property.name == propName;
                            });

                        if (it == entDef.properties.end()) {
                            throw std::runtime_error(
                                fmt::format("Property '{}' to set default "
                                            "value not found in entity "
                                            "definition at line {}",
                                            propName, numLine));
                        }
                        // Set the default value if the property is found
                        it->defaultValue = defaultValue;
                    } else if (tokens[1].value == "GE_Documentation") {
                        auto propName = tokens[3].value;
                        auto documentation = tokens[5].value;
                        removeQuotes(documentation);
                        auto it = std::find_if(
                            entDef.properties.begin(), entDef.properties.end(),
                            [&](const Property& property) {
                                return property.name == propName;
                            });

                        if (it == entDef.properties.end()) {
                            throw std::runtime_error(
                                fmt::format("Property '{}' to set default "
                                            "value not found in entity "
                                            "definition at line {}",
                                            propName, numLine));
                        }
                        // Set the default value if the property is found
                        it->documentation = documentation;
                    } else if (tokens[1].value == "GE_Origin") {
                        auto propName = tokens[3].value;

                        auto it = std::find_if(
                            entDef.properties.begin(), entDef.properties.end(),
                            [&](const Property& property) {
                                return property.name == propName;
                            });

                        if (it == entDef.properties.end()) {
                            throw std::runtime_error(
                                fmt::format("Property '{}' to set default "
                                            "value not found in entity "
                                            "definition at line {}",
                                            propName, numLine));
                        }
                        it->isOrigin = true;
                    } else if (tokens[1].value == "GE_Angles") {
                        auto propName = tokens[3].value;

                        auto it = std::find_if(
                            entDef.properties.begin(), entDef.properties.end(),
                            [&](const Property& property) {
                                return property.name == propName;
                            });

                        if (it == entDef.properties.end()) {
                            throw std::runtime_error(
                                fmt::format("Property '{}' to set default "
                                            "value not found in entity "
                                            "definition at line {}",
                                            propName, numLine));
                        }
                        it->isAngles = true;
                    } else if (tokens[1].value == "GE_Arc") {
                        auto propName = tokens[3].value;

                        auto it = std::find_if(
                            entDef.properties.begin(), entDef.properties.end(),
                            [&](const Property& property) {
                                return property.name == propName;
                            });

                        if (it == entDef.properties.end()) {
                            throw std::runtime_error(
                                fmt::format("Property '{}' to set default "
                                            "value not found in entity "
                                            "definition at line {}",
                                            propName, numLine));
                        }
                        it->isArc = true;
                    } else if (tokens[1].value == "GE_Radius") {
                        auto propName = tokens[3].value;

                        auto it = std::find_if(
                            entDef.properties.begin(), entDef.properties.end(),
                            [&](const Property& property) {
                                return property.name == propName;
                            });

                        if (it == entDef.properties.end()) {
                            throw std::runtime_error(
                                fmt::format("Property '{}' to set default "
                                            "value not found in entity "
                                            "definition at line {}",
                                            propName, numLine));
                        }
                        it->isRadius = true;
                    }
                } else {
                    // End of reading struct, gather name for the ent def
                    if (tokens.size() >= 2 && tokens[0].value == "}") {
                        entDef.name = tokens[1].value;
                        ents.push_back(entDef);
                        status = ParserStatus::None;
                        continue;
                    }

                    // If type is a pointer like char*, then it's part of the
                    // name
                    if (tokens[1].value == "*") {
                        tokens[0].value.append("*");
                        tokens.erase(tokens.begin() + 1);
                    }

                    Property prop;
                    prop.type = tokens[0].value;
                    prop.name = tokens[1].value;
                    prop.isPublished = isPublished;
                    entDef.properties.push_back(prop);
                }
            }
        }

        // If we end parsing the file and the parser status is different from
        // none then something happened and we need to throw an error
        if (status == ParserStatus::FindStartBraceStruct) {
            throw std::runtime_error(
                fmt::format("Expected '{' in typedef struct <name> "
                            "at line {}",
                            numLine));
        }
    }

   private:
    /**
     * Removes double quotes from the given string at beggining and end.
     */
    void removeQuotes(std::string& str) {
        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
    }
};
