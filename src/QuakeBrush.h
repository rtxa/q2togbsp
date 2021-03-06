#pragma once

#include <vector>
#include "QuakeFace.h"


class QuakeBrush {
public:
	void insertFace(QuakeFace face);
	void printFaces();
	//void getFaces();

	// Iterators
	inline std::vector<QuakeFace>::const_iterator QuakeBrush::begin() const { return m_faces.begin(); };
	inline std::vector<QuakeFace>::const_iterator QuakeBrush::end() const { return m_faces.end(); };

private:
	std::vector<QuakeFace> m_faces;
};

