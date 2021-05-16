#pragma once

#include <vector>

#include <string>
#include <fstream>
#include "../structures/QuakeEntity.h"
#include "../structures/QuakeBrush.h"
#include "../utils/StringTokenizer.h"
#include "../structures/QuakeMap.h"

class QuakeParser {
public:
	/*
	 * Parses the .map quake file and stores it in a QuakeMap class (a data structure)
	 */
	bool processMap(std::string filename, QuakeMap& qMap);

private:
	bool parseKeyValue(std::string line);
	bool parseFace(std::string line);
	bool parseVector(StringTokenizer& st);
	std::vector<Vector3f> parsePlane(StringTokenizer& st);

	QuakeEntity m_entity; /** Contains a QuakeEntity */
	QuakeBrush m_brush;
	QuakeFace m_face;
	std::string m_key;
	std::string m_value;
	Vector3f m_point;
	std::fstream m_quakeMap;
};
