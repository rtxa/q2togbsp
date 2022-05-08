#pragma once

#include "GenesisFace.h"

#include <vector>

class GenesisBrush {
public:
	enum BrushContentFlags : int {
		Solid = (1 << 0),		// Solid (Visible)
		Window = (1 << 1),		// Window (Visible)
		Empty = (1 << 2),		// Empty but Visible (water, lava, etc...)
		Translucent = (1 << 3),	// Vis will see through it
		Wavy = (1 << 4),		// Wavy (Visible)
		Detail = (1 << 5),		// Won't be included in vis oclusion
		Clip = (1 << 6),		// Structural but not visible
		Hint = (1 << 7),		// Primary splitter (Non-Visible)
		Area = (1 << 8),		// Area seperator leaf (Non-Visible)
		Flocking = (1 << 9),	// flocking flag.  Not really a contents type
		Sheet = (1 << 10)		// flocking flag.  Not really a contents type
		// flags 11 through 15 are reserved for future expansion.
		// flags 16 through 31 are user flags.
	};

	GenesisBrush() : m_flags{BrushContentFlags::Solid} {};

	int getFlags() const;
	int getNumFaces() const;
	void setFlags(int flags);
	void insertFace(const GenesisFace& face);

	std::vector<GenesisFace>& faces();
	const std::vector<GenesisFace>& faces() const;

	void printBrush() const;
	
private:
	int m_flags{0};
	std::vector<GenesisFace> m_faces;
};

