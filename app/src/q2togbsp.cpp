// q2togbsp.cpp - Converts a Quake 1/2 .map to GBSP binary map format.
// Author: rtxa
// Version 0.1 - 27/09/2020

#include <filesystem>
#include "converter/QuakeToGenesis.h"
#include "parser/QuakeParser.h"
#include "typeparser/EntDefParser.h"
#include "writer/GBSPWriter.h"

#include <argparse/argparse.hpp>

#include <iostream>

namespace fs = std::filesystem;

void processHeader(const fs::path& folderPath, std::vector<EntDef>& entDefs);
void InitCommandLineArgs(argparse::ArgumentParser& program);

int main(int argc, char* argv[]) {
    argparse::ArgumentParser program{"q2togbsp", "0.1"};

    InitCommandLineArgs(program);

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& ex) {
        std::cerr << ex.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    auto input = program.get<std::string>("--input");
    auto output = program.get<std::string>("--output");

    QuakeMap qMap;
    GenesisMap gMap;

    // Step 1: Parse Quake .MAP file
    try {
        qMap = QuakeParser().parse(input);
    } catch (const std::runtime_error& ex) {
        std::cerr << "Failed parsing of Quake map file: " << ex.what() << '\n';
        return 1;
    }

    if (program["--debug-quake"] == true) {
        std::cout << "Printing Quake Map" << '\n';
        std::cout << qMap.dump();
    }

    // Step 2: Convert Quake map data to Genesis map data
    try {
        gMap = QuakeToGenesis().convert(qMap);
    } catch (...) {  // No exception thrown implemented yet
        std::cout << "Failed converting Quake map to Genesis!\n";
        return 1;
    }

    if (program["--debug-genesis"] == true) {
        std::cout << "Printing Genesis Map" << '\n';
        std::cout << gMap.dump();
    }

    auto headersArg = program.get<std::string>("--headers");
    std::vector<std::string> headersPaths;

    // Using a string stream to split the string
    std::istringstream ss(headersArg);
    std::string item;

    // Split the string using the semicolon delimiter
    while (std::getline(ss, item, ';')) {
        headersPaths.emplace_back(item);  // Move item into the vector
    }

    // Specify the path to the folder
    fs::path folderPath(headersArg);

    // Process the headers and store them
    auto entDefs = std::vector<EntDef>();
    for (const auto& path : headersPaths) {
        processHeader(path, entDefs);
    }

    // Step 3: Finally write the serialized Genesis map file
    try {
        GBSPWriter().writeGBSPFile(output, gMap, entDefs);
    } catch (const std::runtime_error& ex) {
        std::cerr << "Failed writing Genesis map to GBSP binary format: ";
        std::cerr << ex.what() << '\n';
        return 1;
    }

    std::cout << "Quake map has been converted successfully to "
              << "GBSP binary map format\n";

    return 0;
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

void InitCommandLineArgs(argparse::ArgumentParser& program) {
    program.add_argument("-i", "--input")
        .required()
        .help("specify the input file.");

    program.add_argument("-o", "--output")
        .required()
        .help("specify the output file.");

    program.add_argument("-dq", "--debug-quake")
        .help("display debug information from Quake.")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("-dg", "--debug-genesis")
        .help("display debug information from Genesis.")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("-hd", "--headers")
        .help("folders path to get headers, delimited with ;.")
        .required()
        .default_value(std::string(""));
}