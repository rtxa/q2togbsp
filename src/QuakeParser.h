#pragma once

#include <vector>

#include <string>
#include <fstream>
#include "QuakeEntity.h"
#include "QuakeBrush.h"
#include "StringTokenizer.h"
#include "QuakeMap.h"

class QuakeParser {
public:
	enum class Result {
		RESULT_SUCCED,
		RESULT_FAIL
	};

	/*
	 * Parses the .map quake file and stores it in a QuakeMap class (a data structure)
	 */
	bool processMap(const std::string filename, QuakeMap& qMap);

private:
	Result parseKeyValue(const std::string line);
	Result parseFace(const std::string line);
	Result parseVector(StringTokenizer * st);
private:
	QuakeEntity m_entity; /**< Detailed description after the member */
	QuakeBrush m_brush;
	QuakeFace m_face;
	std::string m_key;
	std::string m_value;
	Vector3f m_point;
	std::fstream m_quakeMap;
	std::vector<QuakeEntity> m_entities;
};
