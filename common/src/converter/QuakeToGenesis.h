#pragma once

#include "structures/GenesisMap.h"
#include "structures/QuakeMap.h"

class QuakeToGenesis {
   public:
    /*
     * Converts a QuakeMap to GenesisMap.
     */
    GenesisMap convert(const QuakeMap& qMap);

   private:
    /*
     * Converts QuakeFace to GenesisFace.
     */
    static bool convertFace(const QuakeFace& qFace, GenesisFace& gFace);

    /*
     * Converts a plane (p0, p1 and p2) to its normal form (normal and
     * distance).
     *
     * @return True if was converted successfully, otherwise false.
     */
    static bool findNormalFromPoints(const Vector3f points[3],
                                  Vector3f& normal,
                                  float& distance);

    /*
     * Align texture coordinates to the world coordinate system.
     */
    static void alignTextureToWorld(Vector3f normal,
                                     float rotation,
                                     Vector3f& uVec,
                                     Vector3f& vVec);

    bool convertEnt(const QuakeEntity& qEnt, GenesisEntity& gEnt);

    /*
     * Generates an unique name for the entity classname:
     * Example: if classname is "light" and there are already 3 lights
     * the next light will be called "light4"
     */
    std::string getNameForEntity(const std::string& classname);

    /*
     * Convert Quake coordinates to Genesis
     */
    static bool convertCoords(const std::string& origin, Vector3f& vector);

    std::map<std::string, int>
        m_numEntsByClass;  // used for %name% to count number of entities by
                           // class to assign a name
};