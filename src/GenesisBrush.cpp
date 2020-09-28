#include "GenesisBrush.h"

GenesisBrush::GenesisBrush() {
	m_flags = BrushContentFlags::Solid;
}

int GenesisBrush::getFlags() {
	return m_flags;
}

int GenesisBrush::getNumFaces() {
	return m_faces.size();
}

void GenesisBrush::setFlags(int flags) {
	m_flags = flags;
}

void GenesisBrush::insertFace(GenesisFace face) {
	m_faces.push_back(face);
}

std::vector<GenesisFace>::const_iterator GenesisBrush::begin() const {
	return m_faces.begin();
}

std::vector<GenesisFace>::const_iterator GenesisBrush::end() const {
	return m_faces.end();
}

void GenesisBrush::printBrush() const {
	for (auto ptr = m_faces.begin(); ptr < m_faces.end(); ptr++) {
		ptr->printFace();
	}
}
