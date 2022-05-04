#include "GenesisBrush.h"

GenesisBrush::GenesisBrush() {
	m_flags = BrushContentFlags::Solid;
}

int GenesisBrush::getFlags() const {
	return m_flags;
}

int GenesisBrush::getNumFaces() const {
	return m_faces.size();
}

void GenesisBrush::setFlags(int flags) {
	m_flags = flags;
}

void GenesisBrush::insertFace(GenesisFace face) {
	m_faces.push_back(face);
}

std::vector<GenesisFace>& GenesisBrush::faces() {
	return m_faces;
}

const std::vector<GenesisFace>& GenesisBrush::faces() const {
	return m_faces;
}

void GenesisBrush::printBrush() const {
	for (auto ptr = m_faces.begin(); ptr < m_faces.end(); ptr++) {
		ptr->printFace();
	}
}
