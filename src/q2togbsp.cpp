// q2togbsp.cpp - Converts a Quake 1/2 .map to GBSP binary map format.
// Author: rtxa
// Version 0.1 - 27/09/2020

#include "converter/QuakeToGenesis.h"
#include "parser/QuakeParser.h"
#include "writer/GBSPWriter.h"

#include <argparse/argparse.hpp>

#include <iostream>

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
		QuakeParser().processMap(input, qMap);
	} catch (const std::runtime_error& ex) {
		std::cerr << "Failed parsing of Quake map file: " << ex.what() << '\n';
		return 1;
	}

	if (program["--debug-quake"] == true) {
		std::cout << "Printing Quake Map" << '\n';
		std::cout << qMap.dump() << '\n';
	}

	// Step 2: Convert Quake map data to Genesis map data
	try {
		gMap = QuakeToGenesis().convert(qMap);
	} catch (...) { // No exception thrown implemented yet
		std::cout << "Failed converting Quake map to Genesis!\n";
		return 1;        
	}

	if (program["--debug-genesis"] == true) {
		gMap.printAll();
	}

    // Step 3: Finally write the serialized Genesis map file
	try {
		GBSPWriter().writeGBSPFile(output, gMap);
	} catch (const std::runtime_error& ex) {
		std::cerr << "Failed writing Genesis map to GBSP binary format: ";
		std::cerr << ex.what() << '\n';
		return 1;
	}

	std::cout << "Quake map has been converted successfully to GBSP binary map format\n";

	return 0;
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
}