#include <doctest/doctest.h>

#include "parser/QuakeParser.h"
#include "structures/GenesisMap.h"
#include "typeparser/EntDefParser.h"
#include "writer/GBSPReader.h"
#include "writer/GBSPWriter.h"

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <tuple>

namespace fs = std::filesystem;
void processHeader(const fs::path& folderPath, std::vector<EntDef>& entDefs);

TEST_CASE("Test EntDef Type Parser") {
    using T = std::tuple<std::vector<std::string>, std::string, std::string>;
    auto testCases =
        std::vector<T>{{{"test_data/typeparser/entidad3d_headers",  // E3D
                         "test_data/typeparser/entidad3d_headers/game",
                         "test_data/typeparser/entidad3d_headers/fx"},
                        "test_data/typeparser/only-typedefs-e3d.map",
                        "test_data/typeparser/fixedentdefs_gtest.h"},
                       {{"test_data/typeparser/gtest_headers/FX",  // GTest
                         "test_data/typeparser/gtest_headers/Game"},
                        "test_data/typeparser/only-typedefs-gtest.map",
                        "test_data/typeparser/fixedentdefs_gtest.h"},
                       {{"test_data/typeparser/rf_headers"},  // RF
                        "test_data/typeparser/only-typedefs-rf.map",
                        "test_data/typeparser/fixedentdefs_rf.h"}};

    // This subcase compares the properties from the parsed entities
    // with the properties from the expected Genesis map files
    SUBCASE("Test properties are equal") {
        for (const auto& testCase : testCases) {
            const auto& [headersPaths, expectedMapPath, fixedEntDefs] =
                testCase;

            // Parse the fixed entity definitions first, then parse the headers
            auto entDefs = std::vector<EntDef>();
            EntDefParser::parse(fixedEntDefs, entDefs);
            for (const auto& path : headersPaths) {
                INFO("Processing header: " << path);
                processHeader(path, entDefs);
            }

            // Write our new entity definitions to read it back later and
            // compare with what is expected
            GenesisMap temp;
            temp.insertEntity(GenesisEntity());
            GBSPWriter().writeGBSPFile("test_data/typeparser/new-typedefs.map",
                                       temp, entDefs);

            // Read the expected entity definitions
            GenesisMap expectedTypeDefs;
            GBSPReader::read(expectedMapPath, expectedTypeDefs);

            // Read the Genesis map file that was just written
            GenesisMap newTypeDefs;
            GBSPReader::read("test_data/typeparser/new-typedefs.map",
                             newTypeDefs);

            // Now ensure that entities definitions generated by my parser are
            // the same as the ones from the other Genesis3D forks.
            REQUIRE(expectedTypeDefs.entities().size() ==
                    newTypeDefs.entities().size());

            // Skip worldspawn entity and compare the rest
            for (int i = 1; i < expectedTypeDefs.entities().size(); ++i) {
                const auto& ent = expectedTypeDefs.entities()[i];
                const auto& newEnt = newTypeDefs.entities()[i];
                REQUIRE(ent.properties().size() == newEnt.properties().size());
                for (const auto& [key, value] : ent.properties()) {
                    const auto& newValue = newEnt.properties().at(key);
                    REQUIRE(value == newValue);
                }
            }
        }
    }
}

void processHeader(const fs::path& folderPath, std::vector<EntDef>& entDefs) {
    try {
        // Check if the path exists and is a directory
        if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
            // Iterate through the files in the directory
            for (const auto& entry : fs::directory_iterator(folderPath)) {
                if (fs::is_regular_file(entry.status()) &&
                    entry.path().extension() == ".h") {
                    std::cout << "File: " << entry.path().filename()
                              << std::endl;
                    EntDefParser::parse(entry.path().string(), entDefs);
                }
            }
        } else {
            std::cerr << "Path does not exist or is not a directory."
                      << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}