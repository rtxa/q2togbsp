#include "QuakeBrush.h"
#include <iostream>

void QuakeBrush::insertFace(const QuakeFace face) {
	// probably i should check the face is initialized correctly
	m_faces.push_back(face);
}

void QuakeBrush::printFaces() {
	for (auto ptr = m_faces.begin(); ptr < m_faces.end(); ptr++) {
		ptr->printFace();
	}
}