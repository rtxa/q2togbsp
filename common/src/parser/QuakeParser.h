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
	/**
	 * @brief Parses a Quake map file.
	 * 
	 * @param path File path to the Quake map file
	 * 
	 * @return QuakeMap Contains the parsed file
	 * @throws QuakeParserException On parsing fail
	 */
	QuakeMap parse(const std::string& path);

private:
	/**
	 * @brief Parses an entity section from the Quake map file.
	 * 
	 * @param file File stream with current line
	 * 
	 * @return QuakeEntity
	 * @throw QuakeParserException on parse error 
	 */
	QuakeEntity parseEntity(std::fstream& file);

	/**
	 * @brief Parses a brush section from the Quake map file.
	 * 
	 * @param file File stream
	 * 
	 * @return QuakeEntity 
	 * @throw QuakeParserException on parse error 
	 */
	QuakeBrush parseBrush(std::fstream& file);

	/**
	 * @brief Parses a brush face section from the Quake map file.
	 * 
	 * @param file File stream
	 * 
	 * @return QuakeEntity 
	 * @throw QuakeParserException on parse error 
	 */
	QuakeFace parseBrushFace(const std::string& line);
	
	/**
	 * @brief Parses an entity property from the Quake map file.
	 * 
	 * @param file File stream
	 * 
	 * @return QuakeEntity 
	 * @throw QuakeParserException on parse error 
	 */
	std::pair<std::string, std::string> parseEntityProperty(const std::string& line);

	/**
	 * @brief Parses a plane  from the Quake map file.
	 * 
	 * @param file File stream
	 * 
	 * @return QuakeEntity 
	 * @throw QuakeParserException on parse error 
	 */
	std::vector<Vector3f> parsePlane(StringTokenizer& st);

	/**
	 * @brief Parses a vector of the Quake map file
	 * 
	 * @param file File stream
	 * 
	 * @return QuakeEntity 
	 * @throw QuakeParserException on parse error 
	 */
	Vector3f parseVector(StringTokenizer& st);
};
