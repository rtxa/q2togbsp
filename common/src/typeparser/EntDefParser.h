#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "fmt/format.h"

#include "typeparser/CScanner.h"
#include "typeparser/EntDef.h"

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
     *  @param entDefs A list of EntDef
     *
     *  @return A list of EntDef
     *  @throws std::runtime_error if the file cannot be opened or parsing fails
     */
    static void parse(const std::string& filename,
                      std::vector<EntDef>& entDefs) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error(
                fmt::format("Could not open file: {}", filename));
        }

        CScanner scanner(file);
        EntDef entDef;
        bool isPublished = false;
        bool foundType = false;

        while (true) {
            auto token = scanner.nextToken();
            if (token.type == CTokenType::Eof)
                break;

            if (token.value == "#pragma" &&
                (token.flags & CTokenFlags::StartOfLine)) {
                parsePragma(scanner, entDef, foundType);
            } else if (foundType && token.value == "typedef") {
                parseTypedef(scanner, entDef, isPublished, entDefs, foundType);
            }
        }
    }

   private:
    static void parsePragma(CScanner& scanner,
                            EntDef& entDef,
                            bool& foundGeType) {
        auto token = scanner.nextToken();
        if (token.value == "GE_Type") {
            scanner.scanExpecting("(");
            auto typeIcon = scanner.nextToken().value;
            removeQuotes(typeIcon);
            entDef = EntDef();  // Reset entDef for a new struct
            entDef.typeIcon = typeIcon;
            scanner.scanExpecting(")");
            foundGeType = true;
        }
    }

    static void parseTypedef(CScanner& scanner,
                             EntDef& entDef,
                             bool& isPublished,
                             std::vector<EntDef>& entDefs,
                             bool& foundType) {
        auto token = scanner.nextToken();  // Expecting "struct"
        if (token.value == "struct") {
            scanner.nextToken();  // Skip struct name
            token = scanner.nextToken();
            if (token.value == ";") {
                // Skip forward declaration
            } else if (token.value == "{") {
                parseStruct(scanner, entDef, isPublished);
                entDefs.push_back(entDef);
                foundType = false;
            }
        }
    }

    static void parseStruct(CScanner& scanner,
                            EntDef& entDef,
                            bool& isPublished) {
        auto token = scanner.nextToken();
        while (token.type != CTokenType::Eof) {
            // Reading special pragmas
            if (token.value == "#pragma") {
                auto name = scanner.nextToken().value;
                parseSpecialField(scanner, name, entDef, isPublished);
            } else if (token.value == "}") {  // End of struct
                entDef.name = scanner.nextToken().value;
                isPublished = false;  // Reset visibility for a new struct
                scanner.scanExpecting(";");
                break;
            } else {  // Reading struct member
                auto type = token;
                token = scanner.nextToken();
                while (token.value == "*") {  // Handle pointers
                    type.value += "*";
                    token = scanner.nextToken();
                }
                scanner.scanExpecting(";");

                EntDefProp prop;
                prop.type = type.value;
                prop.name = token.value;
                prop.isPublished = isPublished;
                entDef.properties.push_back(prop);
            }
            token = scanner.nextToken();
        }
    }

    static void parseSpecialField(CScanner& scanner,
                                  const std::string& fieldName,
                                  EntDef& entDef,
                                  bool& isPublished) {
        // clang-format off
        if (fieldName == "GE_Published") {
            isPublished = true;
        } else if (fieldName == "GE_Private") {
            isPublished = false;
        } else if (fieldName == "GE_Origin") {
            parseField(scanner, entDef, [](auto& prop) { prop.isOrigin = true; });
        } else if (fieldName == "GE_Angles") {
            parseField(scanner, entDef, [](auto& prop) { prop.isAngles = true; });
        } else if (fieldName == "GE_Arc") {
            parseField(scanner, entDef, [](auto& prop) { prop.isArc = true; });
        } else if (fieldName == "GE_Radius") {
            parseField(scanner, entDef, [](auto& prop) { prop.isRadius = true; });
        } else if (fieldName == "GE_DefaultValue") {
            parseFieldWithDefaultValue(scanner, entDef);
        } else if (fieldName == "GE_Documentation") {
            parseFieldWithDocumentation(scanner, entDef);
        } else {
            std::cout << fmt::format(
                "Warning: Unrecognized special field '{}'\n", fieldName);
        }
        // clang-format on
    }

   private:
    static void parseField(
        CScanner& scanner,
        EntDef& entDef,
        const std::function<void(EntDefProp&)>& setProperty) {
        scanner.scanExpecting("(");
        auto propName = scanner.nextToken().value;
        auto it = findProperty(entDef, propName);
        if (it != entDef.properties.end()) {
            setProperty(*it);
        }
        scanner.scanExpecting(")");
    }

    static void parseFieldWithDefaultValue(CScanner& scanner, EntDef& entDef) {
        scanner.scanExpecting("(");
        auto propName = scanner.nextToken().value;
        auto it = findProperty(entDef, propName);
        if (it != entDef.properties.end()) {
            scanner.scanExpecting(",");
            auto value = scanner.nextToken().value;
            removeQuotes(value);
            it->defaultValue = value;
        }
        scanner.scanExpecting(")");
    }

    static void parseFieldWithDocumentation(CScanner& scanner, EntDef& entDef) {
        scanner.scanExpecting("(");
        auto propName = scanner.nextToken().value;
        auto it = findProperty(entDef, propName);
        if (it != entDef.properties.end()) {
            scanner.scanExpecting(",");
            auto value = scanner.nextToken().value;
            removeQuotes(value);
            it->documentation = value;
        }
        scanner.scanExpecting(")");
    }

    static std::vector<EntDefProp>::iterator findProperty(
        EntDef& entDef,
        const std::string& propName) {
        return std::find_if(entDef.properties.begin(), entDef.properties.end(),
                            [&](const EntDefProp& property) {
                                return property.name == propName;
                            });
    }
    /**
     * Removes double quotes from the given string at beggining and end.
     */
    static void removeQuotes(std::string& str) {
        str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
    }
};
