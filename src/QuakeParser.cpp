#include "QuakeParser.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// podria definir en la clase quakrparser un convertto() como virtual, y redefinirlo en la clase quaketogenesis

bool QuakeParser::processMap(const std::string filename, QuakeMap& qMap) {
	m_quakeMap.open(filename, std::ios::in);

	if (!m_quakeMap.is_open()) {
		std::cout << "runtime error: not able to open quake map file" << '\n';
		return false;
	}

	if (m_quakeMap.eof()) {
		std::cout << "runtime error: file is empty" << '\n';

		return false;
	}

	// not initialized
	bool readingEnt = false;
	bool readingBrush = false;

	std::string line;
	std::string identifier;
	Result result;

	while (getline(m_quakeMap, line)) {
		//std::cout << "Reading line: " << line << '\n';
		StringTokenizer st(line);
		
		if (st.hasMoreTokens()) {
			identifier = st.nextToken();
		} else {
			//std::cout << "no more lines\n";
			return false;
		}
		
		// ignore comments
		if (identifier.find("//") == 0) {
			continue;
		}

		if (identifier == "{") {
			if (readingEnt) {
				if (readingBrush) {
					std::cout << "Unexpected opening bracket when reading brush.\n";
					return false;
				} else {
					//std::cout << "New brush\n";
					m_brush = QuakeBrush();
					readingBrush = true;
				}
				continue;
			} else {
				m_entity = QuakeEntity();
				readingEnt = true;
				continue;
			}
		} else if (identifier == "}") {
			if (readingBrush) { // finished reading brush
				//std::cout << "Insert brush\n";
				m_entity.insertBrush(m_brush);
				readingBrush = false;
			} else if (readingEnt) { // finished reading ent
				qMap.insertEntity(m_entity);
				readingEnt = false;
			}
		}

		if (line.find("\"") == 0) { // reading key value
			if (readingBrush) {
				std::cout << "Unexpected keyvalue when reading brush.\n";
				return false;
			}
			result = parseKeyValue(line);
			if (result != Result::RESULT_SUCCED) {
				std::cout << "Unexpected end of key value data" << '\n';
				return false;
			}
			m_entity.insertKeyValue(m_key, m_value);
		} else if (line.find("(") == 0) { // reading face
			result = parseFace(line);
			if (result != Result::RESULT_SUCCED) {
				std::cout << "Unexpected end of face data" << '\n';
				return false;
			}
			//std::cout << "Insertando nueva cara a brush" << '\n';

			m_brush.insertFace(m_face);
		}

	}

	if (readingBrush) {
		std::cout << "Unexpected end of brush data" << '\n';
		return false;
	} else if (readingEnt) {
		std::cout << "Unexpected end of entity data" << '\n';
		return false;
	}

	std::cout << "File proccesed succesfully" << '\n';
	
	return true;
}

// parse the value and store it in m_entity
QuakeParser::Result QuakeParser::parseKeyValue(const std::string line) {
	StringTokenizer st(line);

	if (st.countTokens() < 2) {
		std::cout << "not enough keys to parse" << '\n';
		return Result::RESULT_FAIL;
	}

	std::string key, value;
	m_key = st.nextToken();
	m_value = st.nextToken();

	return Result::RESULT_SUCCED;
}

QuakeParser::Result QuakeParser::parseFace(const std::string line) {
	StringTokenizer st(line);

	std::string identifier;
	std::vector<Vector3f> points;

	// read 3 points of the plane
	while (true) {
		if (!st.hasMoreTokens()) {
			return Result::RESULT_FAIL;
		}
		identifier = st.nextToken();
		if (identifier == "(") {
			parseVector(&st);
			points.push_back(m_point);
		} else if (identifier == ")") {
			continue;
		} else { // no more planes to read
			break;
		}
	}

	if (points.size() == 3) {
		m_face.setPlane(points[0], points[1], points[2]);
	}

	// Now read additional texture information (tex name, offset, rotation and scale)

	m_face.setTextureName(identifier);

	if (!st.hasMoreTokens()) {
		return Result::RESULT_FAIL;
	}

	try {
		m_face.setOffsetX(st.nextTokenFloat());
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	if (!st.hasMoreTokens()) {
		return Result::RESULT_FAIL;
	}

	try {
		m_face.setOffsetY(st.nextTokenFloat());
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	if (!st.hasMoreTokens()) {
		return Result::RESULT_FAIL;
	}

	try {
		m_face.setRotation(st.nextTokenFloat());
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	if (!st.hasMoreTokens()) {
		return Result::RESULT_FAIL;
	}

	try {
		m_face.setScaleX(st.nextTokenFloat());
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	if (!st.hasMoreTokens()) {
		return Result::RESULT_FAIL;
	}

	try {
		m_face.setScaleY(st.nextTokenFloat());
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}


	// read Quake 2 parameters if they exist
	if (st.countTokens() < 3) {
		return Result::RESULT_SUCCED;
	}

	try {
		m_face.setContentFlags(static_cast<int>(st.nextTokenFloat()));
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	try {
		m_face.setSurfaceFlags(static_cast<int>(st.nextTokenFloat()));
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	try {
		m_face.setLightIntensity(static_cast<int>(st.nextTokenFloat()));
	}
	catch (...) {
		std::cout << "Error in parsing token to float" << '\n';
	}

	//m_face.printFace();

	return Result::RESULT_SUCCED;
}

QuakeParser::Result QuakeParser::parseVector(StringTokenizer *st) {
	float point[3];
	std::string identifier;
	for (int i = 0; i < 3; i++) {
		if (st->hasMoreTokens()) {
			identifier = st->nextToken();
			try {
				point[i] = std::stof(identifier);
			} catch (...) {
				return Result::RESULT_FAIL;
			}
		} else {
			return Result::RESULT_FAIL;
		}
	}
	m_point.set(point[0], point[1], point[2]);
	return Result::RESULT_SUCCED;
}