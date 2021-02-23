// q2togbsp.cpp - Converts a Quake 1/2 .map to GBSP binary map format.
// Author: rtxa
// Version 0.1 - 27/09/2020

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "QuakeParser.h"
#include "QuakeMap.h"
#include "QuakeToGenesis.h"
#include "GenesisMap.h"
#include "GBSPWriter.h"

int explodeHeadersDir(const std::string& input, std::vector<std::string>& output, const std::string delim);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "No file input specified for converting!\n";
		return 1;
	} else if (argc < 3) {
		std::cout << "No file output specified for converting!\n";
		return 1;
	}

	QuakeMap qMap = QuakeMap();
	GenesisMap gMap = GenesisMap();

	QuakeParser parser = QuakeParser();

// 1. PROCESS QUAKE MAP
	if (!parser.processMap(argv[1], qMap)) {
		std::cout << "Failed proccesing Quake map!\n";
		return 1;
	}

// 2. CONVERT MAP TO GENESIS FORMAT
	QuakeToGenesis converter = QuakeToGenesis();

	if (!converter.convertTo(qMap, gMap)) {
		std::cout << "Failed converting Quake map to Genesis!\n";
		return 1;        
	}

	//gMap.printAll();

// 3. PROCESS G3D ENTITY DEFINITIONS AND STORE THEM IN THE NEW GENESIS MAP
	std::vector<std::string> headersDir;

	// get headers dirs from command line arguments
	// with format -headersdir "C:/with spaces;D:/otherFolder"
	for (int i = 0; i < argc; i++) {
		if (std::string(argv[i]) == "-headersdir") {
			if (i + 1 == argc) {
				std::cout << "Error: expected argument for -headersdir\n";
				return 1;
			}
			
			explodeHeadersDir(std::string(argv[i + 1]), headersDir, ";");
		}
	}

	// now process .h files from the dirs the user has got input
	for (auto path : headersDir) {
		if (std::filesystem::is_directory(path)) {
			for (auto& entry : std::filesystem::directory_iterator(path)) {
				if (entry.is_regular_file()) {
					if (entry.path().has_extension() && entry.path().extension() == ".h") {
						std::cout << "Filename " << entry.path().filename() << "\n";
						// do actions with file (EntDefParser)
					}
				}
			}
		} else {
			std::cout << "Warning: directory \"" << path << "\" in -headersdir doesn't exist.\n";
			continue;
		}
	}


// 4. OUTPUT CONVERTED GENESIS MAP TO .BSP 
	GBSPWriter gbsp;
	if (!gbsp.writeGBSPFile(argv[2], gMap)) {
		std::cout << "Failed writing Genesis map to GBSP binary format!\n";
		return 1;
	}

	std::cout << "Quake map has been converted successfully to GBSP binary map format\n";

	return 0;
}

////////////////////////
//       UTILS        //
////////////////////////

// here we split the dirs by delimiter and put them in a vector of strings
// example of input string: "folder1;folder2;etc"
int explodeHeadersDir(const std::string& input, std::vector<std::string>& output, const std::string delim) {
	auto start = 0U;
	auto end = input.find(delim);

	while (end != std::string::npos) {
		std::cout << input.substr(start, end - start) << std::endl;
		output.insert(output.end(), input.substr(start, end - start));
		start = end + delim.length();
		end = input.find(delim, start);
	}

	// if no delimiters are found then copy the last string if exists
	if (end == std::string::npos && start < input.length()) {
		std::cout << input.substr(start) << std::endl;
		output.insert(output.end(), input.substr(start));
	}

	return 0;
}
