// q2togbsp.cpp - Converts a Quake 1/2 .map to GBSP binary map format.
// Author: rtxa
// Version 0.1 - 27/09/2020

#include <iostream>

#include "parser/QuakeParser.h"
#include "converter/QuakeToGenesis.h"
#include "writer/GBSPWriter.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "No file input specified for converting!\n";
		return 1;
	} else if (argc < 3) {
		std::cout << "No file output specified for converting!\n";
		return 1;
	}

	QuakeMap qMap;
	
	if (!QuakeParser().processMap(argv[1], qMap)) {
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

	//gMap.printAll();

	// TODO i should load entity definitions
	// by reading the .fgd file and generating typedefs automatically

	if (!GBSPWriter().writeGBSPFile(argv[2], gMap)) {
		std::cout << "Failed writing Genesis map to GBSP binary format!\n";
		return 1;
	}

	std::cout << "Quake map has been converted successfully to GBSP binary map format\n";

	return 0;
}
