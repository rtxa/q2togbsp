#pragma once

#include "structures/QuakeMap.h"
#include "structures/QuakeEntity.h"
#include "structures/QuakeBrush.h"

#include "utils/StringTokenizer.h"

#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>

class QuakeParser {
public:
	/*
	 * Parses the .map quake file and stores it in a QuakeMap class (a data structure)
	 */
	static QuakeMap parse(const std::string& path);

private:
	static QuakeMap parseEntities(std::fstream& file);
	static QuakeEntity parseEntity(std::fstream& file);
	static QuakeBrush parseBrush(std::fstream& file);
	static QuakeFace parseBrushFace(const std::string& line);
	static std::pair<std::string, std::string> parseEntityProperty(const std::string& line);
	static std::vector<Vector3f> parsePlane(StringTokenizer& st);
	static Vector3f parseVector(StringTokenizer& st);
};
