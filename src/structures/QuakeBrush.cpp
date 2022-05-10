#include "QuakeBrush.h"

void QuakeBrush::insertFace(const QuakeFace& face) {
	// probably i should check the face is initialized correctly
	m_faces.push_back(face);
}

std::vector<QuakeFace>& QuakeBrush::faces() {
	return m_faces;
}

const std::vector<QuakeFace>& QuakeBrush::faces() const {
	return m_faces;
}

void QuakeBrush::printFaces() const {
	for (const auto& face : m_faces) {
		face.printFace();
	}
}