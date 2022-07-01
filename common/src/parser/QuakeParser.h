#pragma once

#include "structures/QuakeMap.h"
#include "structures/QuakeEntity.h"
#include "structures/QuakeBrush.h"

#include "utils/StringTokenizer.h"

#include <fstream>
#include <string>
#include <vector>

class QuakeParser {
public:
	/*
	 * Parses the .map quake file and stores it in a QuakeMap class (a data structure)
	 */
	void processMap(const std::string& filename, QuakeMap& qMap);

private:
	bool parseKeyValue(const std::string& line);
	bool parseFace(const std::string& line);
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
