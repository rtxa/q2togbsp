#pragma once

#include "QuakeMap.h"
#include "GenesisMap.h"

class QuakeToGenesis {
public:
	/*
	 * Converts a QuakeMap to GenesisMap.
	 */
	bool convertTo(const QuakeMap qMap, GenesisMap& gMap);

private:
	/*
	 * Converts QuakeFace to GenesisFace.
	 */
	bool faceToGenesis(const QuakeFace qFace, GenesisFace& gFace);

	/*
	 * Converts a plane (p0, p1 and p2) to its normal form (normal and distance).
	 * 
	 * @return True if was converted succefully, otherwise false.
	 */
	bool planeToNormalForm(const Vector3f points[3], Vector3f& normal, float& distance);
	
	/*
	 * Converts world texture vectors to UV texture coordinates.
	 */
	void worldTextureVecsToUV(const Vector3f normal, const float rotation, Vector3f& uVec, Vector3f& vVec);

	bool entToGenesis(const QuakeEntity qEnt, GenesisEntity& gEnt);
	/*
	 * Generates an unique name for the entity classname:
	 * Example: if classname is "light" and there are already 3 lights
	 * the next light will be called "light4"
	 */
	const std::string getNameForEntity(const std::string classname);

	/*
	 * Convert Quake coordinates to Genesis
	 */
	bool convertOriginToGenesis(std::string origin,  float& x, float& y, float &z);

	std::map<std::string, int> m_numEntsByClass; // used for %name% to count number of entities by class to assign a name
};