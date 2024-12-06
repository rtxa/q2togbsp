#pragma once

#include "typeparser/EntDef.h"

#include <fmt/format.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FgdGenerator {
   public:
    static void generate(const std::string& outputDir,
                         const std::vector<EntDef>& entDefs) {
        std::ofstream fgdFile(outputDir, std::ios::out);
        if (!fgdFile.is_open()) {
            throw std::runtime_error("Can't open file: " + outputDir);
        }

        for (const auto& entDef : entDefs) {
            if (entDef.name.empty()) {
                throw std::runtime_error("Entity definition name is empty");
            }

            auto hasPublicProperties =
                std::any_of(entDef.properties.begin(), entDef.properties.end(),
                            [](const auto& prop) { return prop.isPublished; });

            // Skip entities with no public properties
            // This is the case for Camera and ModelOrigin
            if (hasPublicProperties) {
                fgdFile << fmt::format("@PointClass color({}) = {}\n",
                                       assignNextColor(), entDef.name);
                fgdFile << "[" << '\n';
                for (const auto& prop : entDef.properties) {
                    if (prop.isPublished) {
                        writeProperty(fgdFile, prop.name, prop.type,
                                      prop.defaultValue, prop.documentation,
                                      prop.isOrigin);
                    }
                }
                fgdFile << "]" << "\n\n";
            }
        }
    }

    static void writeProperty(std::ofstream& fgdFile,
                              const std::string& name,
                              const std::string& type,
                              const std::string& defaultValue,
                              const std::string& documentation,
                              bool isOrigin) {
        static constexpr auto indent = "    ";

        if (isOrigin) {
            // FGD already has an origin property implicitly
            // We don't want to add it twice
            return;
        }

        if (type == "int") {
            fgdFile << indent
                    << fmt::format("{}(integer) : \"{}\" : {} : \"{}\" \n",
                                   name, name,
                                   defaultValue.empty() ? "0" : defaultValue,
                                   documentation);
        } else if (type == "geBoolean") {
            fgdFile << indent
                    << fmt::format("{}(choices) : \"{}\" : \"{}\" : \"{}\" =\n",
                                   name, name,
                                   defaultValue == "True" ? "1" : "0",
                                   documentation);
            fgdFile << indent << "[\n";
            fgdFile << indent << indent << "0 : \"False\"\n";
            fgdFile << indent << indent << "1 : \"True\"\n";
            fgdFile << indent << "]\n";

        } else if (type == "GE_RGBA") {
            fgdFile << indent
                    << fmt::format(
                           "{}(color255) : \"{}\" : \"{}\" : \"{}\" \n", name,
                           name,
                           defaultValue.empty() ? "255 255 255" : defaultValue,
                           documentation);
        } else if (type == "geFloat" || type == "float") {
            fgdFile << indent
                    << fmt::format("{}(float) : \"{}\" : \"{}\" : \"{}\" \n",
                                   name, name,
                                   defaultValue.empty() ? "0.0" : defaultValue,
                                   documentation);
        } else if (type == "geWorld_Model*") {
            fgdFile << indent
                    << fmt::format(
                           "{}(string) : \"{} (Model)\" : \"{}\" : \"{}\" \n",
                           name, name, defaultValue, documentation);
        } else if (type == "geVec3d") {
            // TB doesn't support 'vector' property yet
            fgdFile << indent
                    << fmt::format(
                           "{}(string) : \"{} (Vector)\" : \"{}\" : \"{}\" \n",
                           name, name,
                           defaultValue.empty() ? "0 0 0" : defaultValue,
                           documentation);
        } else if (type == "char*") {
            fgdFile << indent
                    << fmt::format(
                           "{}(string) : \"{} (String)\" : \"{}\" : \"{}\" \n",
                           name, name, defaultValue, documentation);
        } else {
            fgdFile << indent
                    << fmt::format(
                           "{}(string) : \"{} ({})\" : \"{}\" : \"{}\" \n",
                           name, name, type, defaultValue, documentation);
        }
    }

    static const std::vector<std::string>& getColorLookupTable() {
        static const std::vector<std::string> colorLookupTable = {
            "255 182 193",  // Light Pink
            "255 140 0",    // Dark Orange
            "255 215 0",    // Gold
            "144 238 144",  // Light Green
            "173 216 230",  // Light Blue
            "221 160 221",  // Plum
            "255 99 71",    // Tomato
            "135 206 235",  // Sky Blue
            "240 128 128",  // Light Coral
            "255 228 196",  // Bisque
            "186 85 211",   // Medium Orchid
            "240 230 140",  // Light Khaki
            "255 160 122",  // Light Salmon
            "152 251 152",  // Pale Green
            "173 255 47",   // Green Yellow
            "255 240 245",  // Lavender Blush
            "211 211 211",  // Light Gray
            "100 149 237",  // Cornflower Blue
            "255 105 180",  // Hot Pink
            "147 112 219",  // Medium Purple
            "240 248 255",  // Alice Blue
            "255 228 181",  // Papaya Whip
            "255 182 193",  // Light Pink
            "255 127 80",   // Coral
            "60 179 113",   // Medium Sea Green
            "70 130 180",   // Steel Blue
            "178 34 34",    // Firebrick
            "255 165 0",    // Orange
            "127 255 0",    // Chartreuse
            "255 228 225",  // Misty Rose
            "70 130 180",   // Steel Blue
            "255 240 245",  // Lavender Blush
            "240 255 255",  // Azure
            "240 230 140",  // Light Khaki
            "186 85 211",   // Medium Orchid
            "255 0 128",    // Bright Pink
            "72 61 139",    // Dark Slate Blue
            "255 239 0",    // Bright Yellow
            "255 99 71",    // Tomato
            "102 205 170",  // Medium Aquamarine
            "255 228 196",  // Bisque
            "240 128 128",  // Light Coral
            "100 149 237",  // Cornflower Blue
            "255 160 122",  // Light Salmon
            "152 251 152",  // Pale Green
            "50 205 50",    // Lime Green
            "139 69 19",    // Saddle Brown
            "255 228 181",  // Papaya Whip
            "173 216 230",  // Light Blue
            "255 215 0",    // Gold
            "240 255 240",  // Honeydew
            "240 248 255",  // Alice Blue
            "255 192 203",  // Pink
            "240 230 140",  // Light Khaki
            "128 128 255",  // Light Blue
            "255 0 0",      // Red
            "0 255 0",      // Green
            "0 0 255",      // Blue
            "255 255 0",    // Yellow
            "128 0 128",    // Purple
            "128 128 0",    // Olive
            "0 128 128",    // Teal
            "255 69 0",     // Red Orange
            "255 20 147",   // Deep Pink
            "176 224 230",  // Powder Blue
            "255 105 180",  // Hot Pink
            "0 206 209",    // Dark Turquoise
            "240 128 128"   // Light Coral
        };
        return colorLookupTable;
    }

    // Assign color using a static cursor
    static std::string assignNextColor() {
        // Static cursor to keep track of the current color index
        static size_t cursor = 0;
        const auto& colors = getColorLookupTable();

        // Get the current color and increment the cursor
        std::string color = colors[cursor];
        cursor =
            (cursor + 1) % colors.size();  // Wrap around using modulo operator
        return color;
    }
};
