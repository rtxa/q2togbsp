// q2togbsp.cpp - Converts a Quake 1/2 .map to GBSP binary map format.
// Author: rtxa
// Version 0.1 - 27/09/2020

#include "converter/QuakeToGenesis.h"
#include "parser/QuakeParser.h"
#include "writer/GBSPWriter.h"

#include <argparse/argparse.hpp>

#include <iostream>

int main(int argc, char* argv[]) {
	argparse::ArgumentParser program{"q2togbsp", "0.1"};
	
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

	try {
		program.parse_args(argc, argv);
	} catch (const std::runtime_error& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		return 1;
	}

	auto input = program.get<std::string>("--input");
	auto output = program.get<std::string>("--output");

	QuakeMap qMap;
	
	if (!QuakeParser().processMap(input, qMap)) {
		std::cout << "Failed proccesing Quake map!\n";
		return 1;
	}

	if (program.get<bool>("--debug-quake")) {
		qMap.printAll();
	}

	GenesisMap gMap;

	try {
		gMap = QuakeToGenesis().convert(qMap);
	} catch (...) { // No exception thrown implemented yet
		std::cout << "Failed converting Quake map to Genesis!\n";
		return 1;        
	}

	if (program.get<bool>("--debug-genesis")) {
		gMap.printAll();
	}

	if (!GBSPWriter().writeGBSPFile(output, gMap)) {
		std::cout << "Failed writing Genesis map to GBSP binary format!\n";
		return 1;
	}

	std::cout << "Quake map has been converted successfully to GBSP binary map format\n";

	return 0;
}
