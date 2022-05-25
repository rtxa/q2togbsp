#pragma once

#include "QuakeFace.h"

#include <vector>

class QuakeBrush {
public:
	void insertFace(const QuakeFace& face);
	
	std::vector<QuakeFace>& faces();
	const std::vector<QuakeFace>& faces() const;

private:
	std::vector<QuakeFace> m_faces;
};

