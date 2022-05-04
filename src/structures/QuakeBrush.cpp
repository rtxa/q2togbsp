#include "QuakeBrush.h"

void QuakeBrush::insertFace(QuakeFace face) {
	// probably i should check the face is initialized correctly
	m_faces.push_back(face);
}

std::vector<QuakeFace>& QuakeBrush::faces() {
	return m_faces;
}

const std::vector<QuakeFace>& QuakeBrush::faces() const {
	return m_faces;
}

void QuakeBrush::printFaces() {
	for (auto ptr = m_faces.begin(); ptr < m_faces.end(); ptr++) {
		ptr->printFace();
	}
}