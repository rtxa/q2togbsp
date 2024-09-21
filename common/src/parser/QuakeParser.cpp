#include "QuakeParser.h"
#include "QuakeParserException.h"

#include <iostream>
#include <fstream>
#include <sstream>

QuakeMap QuakeParser::parse(const std::string& path) {
	std::fstream file;
	
	file.open(path, std::ios::in);

	if (!file.is_open()) {
		throw QuakeParserException(QuakeParserError::FileNotOpen);
	}

	if (file.eof()) {
		throw QuakeParserException(QuakeParserError::FileEmpty);
	}

	QuakeMap map;

	std::string line;
	while (getline(file, line)) {
		// Skip line comments
		if (line.find("//") == 0) {
			continue;
		}

		// Start of entity definition
		if (line.find('{') == 0) {
			QuakeEntity ent = parseEntity(file);
			map.entities().push_back(ent);			
			continue;
		}

		throw QuakeParserException(QuakeParserError::ExpectedOpenBrace);
	}

	// Post-checks
	if (map.entities().empty()) {
		// bla bla bla...
	}

	return map;
}

QuakeEntity QuakeParser::parseEntity(std::fstream& file) {
	QuakeEntity ent;

	bool endOfEnt = false;

	std::string line;
	while (getline(file, line)) {
		// Skip line comments
		if (line.find("//") == 0) {
			continue;
		}

		// Read entity property
		if (line.find('\"') == 0) {
			auto prop = parseEntityProperty(line);
			ent.addProperty(prop);
			continue;
		}

		// Start of brush block
		if (line.find('{') == 0) {
			QuakeBrush brush = parseBrush(file);
			ent.addBrush(brush);
			continue;
		}

		// End of entity block
		if (line.find('}') == 0) {
			endOfEnt = true;
			break;
		}

		throw QuakeParserException(QuakeParserError::ExpectedCloseBrace);
	}

	if (!endOfEnt) {
		throw QuakeParserException(QuakeParserError::EofWhileParsingEntity);
	}

	return ent;
}

std::pair<std::string, std::string> QuakeParser::parseEntityProperty(const std::string& line) {
	StringTokenizer st(line);

	if (st.countTokens() < 2) {
		throw QuakeParserException(QuakeParserError::NotEnoughTokens);
	}

	std::string key, value;
	key = st.nextToken();
	value = st.nextToken();

	return {key, value};
}

QuakeBrush QuakeParser::parseBrush(std::fstream& file) {
	QuakeBrush brush;

	std::string line;
	while (getline(file, line)) {
		// Skip line comments
		if (line.find("//") == 0) {
			continue;
		}

		// Read brush face
		if (line.find('(') == 0) {
			QuakeFace face = parseBrushFace(line);
			brush.addFace(face);
			continue;
		}
		
		// End of brush reading section
		if (line.find('}') == 0) {
			break;
		}

		// Anything else is unexpected
		throw QuakeParserException(QuakeParserError::UnexpectedTokenBrushFace);
	}

	// Ensure brushes have at least 4 faces
	if (brush.faces().size() < 4) {
		throw QuakeParserException(QuakeParserError::NotEnoughFaces);
	}

	return brush;
}

QuakeFace QuakeParser::parseBrushFace(const std::string& line) {
	StringTokenizer st(line);
	
	QuakeFace face;

	// read 3 points of the plane
	std::vector<Vector3f> points = parsePlane(st);

	face.setPlane(points[0], points[1], points[2]);

	// Now read additional texture information (tex name, offset, rotation X/Y and scale X/Y)
	if (st.countTokens() < 6) {
		// Expected 6 tokens
		throw QuakeParserException(QuakeParserError::NotEnoughTokensBrushFace);
	}

	face.setTextureName(st.nextToken());

	try {
		face.setOffsetX(st.nextTokenFloat());
		face.setOffsetY(st.nextTokenFloat());
		face.setRotation(st.nextTokenFloat());
		face.setScaleX(st.nextTokenFloat());
		face.setScaleY(st.nextTokenFloat());
	} catch (const std::invalid_argument&) {
		throw;
	} catch (const std::out_of_range&) {
		throw;
	}

	// read Quake 2 parameters if they exist
	if (st.countTokens() == 3) {
		try {
			face.setContentFlags(st.nextTokenInt());
			face.setSurfaceFlags(st.nextTokenInt());
			face.setLightIntensity(st.nextTokenInt());
		} catch (const std::invalid_argument&) {
			throw;
		} catch (const std::out_of_range&) {
			throw;
		}
	}

	return face;
}

std::vector<Vector3f> QuakeParser::parsePlane(StringTokenizer& st) {
	std::string token;
	std::vector<Vector3f> points;

	// read 3 points of the plane
	int count = 0;

	while (true) {
		if (!st.hasMoreTokens()) {
			throw QuakeParserException(QuakeParserError::NotEnoughTokensPlane);
		}
		token = st.nextToken();
		if (token == "(") {
			count++;
			points.push_back(parseVector(st));
		} else if (token == ")") {
			if (count == 3) {
				break;
			} else {
				continue;
			}
		}
	}
	return points;
}

Vector3f QuakeParser::parseVector(StringTokenizer& st) {
	if (st.countTokens() < 3) {
		// return false;
	}

	Vector3f v;

	try {
		v.x = std::stof(st.nextToken());
		v.y = std::stof(st.nextToken());
		v.z = std::stof(st.nextToken());
	} catch (const std::invalid_argument& ex) {
		std::cout << "Invalid argument for: " << ex.what() << '\n';
	} catch (const std::out_of_range& ex) {
		std::cout << "Number out of range for: " << ex.what() << '\n';
	}

	return v;
}