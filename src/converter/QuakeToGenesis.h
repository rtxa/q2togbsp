#pragma once

#include "structures/GenesisMap.h"
#include "structures/QuakeMap.h"

class QuakeToGenesis {
public:
	/*
	 * Converts a QuakeMap to GenesisMap.
	 */
	GenesisMap convert(QuakeMap qMap);

private:
	/*
	 * Converts QuakeFace to GenesisFace.
	 */
	static bool faceToGenesis(QuakeFace qFace, GenesisFace& gFace);

	/*
	 * Converts a plane (p0, p1 and p2) to its normal form (normal and distance).
	 * 
	 * @return True if was converted successfully, otherwise false.
	 */
	static bool planeToNormalForm(const Vector3f points[3], Vector3f& normal, float& distance);
	
	/*
	 * Converts world texture vectors to UV texture coordinates.
	 */
	static void worldTextureVecsToUV(Vector3f normal, float rotation, Vector3f& uVec, Vector3f& vVec);

	bool entToGenesis(QuakeEntity qEnt, GenesisEntity& gEnt);
	/*
	 * Generates an unique name for the entity classname:
	 * Example: if classname is "light" and there are already 3 lights
	 * the next light will be called "light4"
	 */
	std::string getNameForEntity(std::string classname);

	/*
	 * Convert Quake coordinates to Genesis
	 */
	static bool convertOriginToGenesis(std::string origin,  float& x, float& y, float &z);

	std::map<std::string, int> m_numEntsByClass; // used for %name% to count number of entities by class to assign a name
};