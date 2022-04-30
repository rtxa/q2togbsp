// q2togbsp.cpp - Converts a Quake 1/2 .map to GBSP binary map format.
// Author: rtxa
// Version 0.1 - 27/09/2020

#include <iostream>

#include "converter/QuakeToGenesis.h"
#include "parser/QuakeParser.h"
#include "utils/InputParser.h"
#include "writer/GBSPWriter.h"

int main(int argc, char* argv[]) {
	InputParser options{argc, argv};

	if (!options.cmdOptionExists("-input")) {
		std::cout << "No file input specified for converting!\n";
		return 1;
	}
	std::string input = options.getCmdOption("-input");
	
	if (!options.cmdOptionExists("-output")) {
		std::cout << "No file output specified for converting!\n";
		return 1;
	}
	std::string output = options.getCmdOption("-output");

	QuakeMap qMap;
	
	if (!QuakeParser().processMap(input, qMap)) {
		std::cout << "Failed proccesing Quake map!\n";
		return 1;
	}

	GenesisMap gMap;

	try {
		gMap = QuakeToGenesis().convert(qMap);
	} catch (...) { // No exception thrown implemented yet
		std::cout << "Failed converting Quake map to Genesis!\n";
		return 1;        
	}

	if (!GBSPWriter().writeGBSPFile(output, gMap)) {
		std::cout << "Failed writing Genesis map to GBSP binary format!\n";
		return 1;
	}

	std::cout << "Quake map has been converted successfully to GBSP binary map format\n";

	return 0;
}
