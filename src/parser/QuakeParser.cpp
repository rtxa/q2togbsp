#include "QuakeParser.h"

#include <iostream>
#include <fstream>
#include <sstream>

// podria definir en la clase quakrparser un convertto() como virtual, y redefinirlo en la clase quaketogenesis

bool QuakeParser::processMap(const std::string& filename, QuakeMap& qMap) {
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
	bool result;

	while (getline(m_quakeMap, line)) {
		StringTokenizer st(line);
		
		// this will skip empty lines
		if (!st.hasMoreTokens()) {
			continue;
		}

		identifier = st.nextToken();
		
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
				m_entity.insertBrush(m_brush);
				readingBrush = false;
			} else if (readingEnt) { // finished reading ent
				qMap.insertEntity(m_entity);
				readingEnt = false;
			}
		}

		if (line.find('\"') == 0) { // reading key value
			if (readingBrush) {
				std::cout << "Unexpected keyvalue when reading brush.\n";
				return false;
			}
			result = parseKeyValue(line);
			if (!result) {
				std::cout << "Unexpected end of key value data" << '\n';
				return false;
			}
			m_entity.insertKeyValue(m_key, m_value);
		} else if (line.find('(') == 0) { // reading face
			result = parseFace(line);
			if (!result) {
				std::cout << "Unexpected end of face data" << '\n';
				return false;
			}

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
bool QuakeParser::parseKeyValue(const std::string& line) {
	StringTokenizer st(line);

	if (st.countTokens() < 2) {
		std::cout << "not enough keys to parse" << '\n';
		return false;
	}

	std::string key, value;
	m_key = st.nextToken();
	m_value = st.nextToken();

	return true;
}

bool QuakeParser::parseFace(const std::string& line) {
	StringTokenizer st(line);
	
	// read 3 points of the plane
	std::vector<Vector3f> points = parsePlane(st);

	if (points.size() == 3) {
		m_face.setPlane(points[0], points[1], points[2]);
	} else {
		std::cout << "Can't read plane from face. Fix your Quake map input.";
		return false;
	}

	// Now read additional texture information (tex name, offset, rotation X/Y and scale X/Y)
	if (st.countTokens() < 6) {
		std::cout << "This line doesn't contain enough tokens to parse. Fix your Quake map input.";
		return false;
	}

	m_face.setTextureName(st.nextToken());

    {
        std::vector<std::string> tokens = st.getTokensList();
        const std::string args[] = { "offset x", "offset y", "rotation", "scale x", "scale y" };

        // validate the data type is float
        for (int i = 0; i < 5; i++) {
            try {
                std::stof(tokens.at(i));
            } catch (...) {
                std::cout << "Error: expected a float in argument " << args[i] << '\n';
                return false;
            }
        }
    }

    m_face.setOffsetX(st.nextTokenFloat());
    m_face.setOffsetY(st.nextTokenFloat());
    m_face.setRotation(st.nextTokenFloat());
    m_face.setScaleX(st.nextTokenFloat());
    m_face.setScaleY(st.nextTokenFloat());

	// read Quake 2 parameters if they exist
	if (st.countTokens() < 3) {
		return true;
	}

    {
        std::vector<std::string> tokens = st.getTokensList();
        const std::string args[] = { "content flags", "surface flags", "light intensity" };

        // validate the data type is an int
        for (int i = 0; i < 3; i++) {
            try {
                std::stoi(tokens.at(i));
            } catch (...) {
                std::cout << "Error: expected an int in argument " + args[i] << '\n';
                return false;
            }
        }
    }

	m_face.setContentFlags(st.nextTokenInt());
	m_face.setSurfaceFlags(st.nextTokenInt());
	m_face.setLightIntensity(st.nextTokenInt());

	return true;
}

std::vector<Vector3f> QuakeParser::parsePlane(StringTokenizer& st) {
	std::string token;
	std::vector<Vector3f> points;

	// read 3 points of the plane
	int count = 0;

	while (true) {
		if (!st.hasMoreTokens()) {
			return std::vector<Vector3f>();
		}
		token = st.nextToken();
		if (token == "(") {
			count++;
			parseVector(st);
			points.push_back(m_point);
		} else if (token == ")") {
			if (count == 3)
				break;
			else
				continue;
		}
	}
	return points;
}

bool QuakeParser::parseVector(StringTokenizer& st) {
	if (st.countTokens() < 3) {
		return false;
	}

	Vector3f v;

	try {
		v.x = std::stof(st.nextToken());
		v.y = std::stof(st.nextToken());
		v.z = std::stof(st.nextToken());
	} catch (const std::invalid_argument& ex) {
		std::cout << "Invalid argument for: " << ex.what() << '\n';
		return false;
	} catch (const std::out_of_range& ex) {
		std::cout << "Number out of range for: " << ex.what() << '\n';
		return false;
	}

	m_point = v;

	return true;
}