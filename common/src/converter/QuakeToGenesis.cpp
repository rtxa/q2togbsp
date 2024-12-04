#include "QuakeToGenesis.h"

#include "utils/StringTokenizer.h"

#include <fmt/format.h>
#include <iostream>
#include <optional>

GenesisMap QuakeToGenesis::convert(const QuakeMap& qMap) {
    GenesisMap gMap;

    for (const auto& ent : qMap.entities()) {
        GenesisEntity gEnt;
        convertEnt(ent, gEnt);
        if (gEnt.getNumKeys() != 0) {
            gMap.insertEntity(gEnt);
        }
    }

    return gMap;
}

bool QuakeToGenesis::convertFace(const QuakeFace& qFace, GenesisFace& gFace) {
    Vector3f points[3];

    for (int i = 0; i < 3; i++) {
        // Switch from RHS Y-Up Quake to RHS Z-Up Genesis coordinates system
        points[i].x = qFace.getPlane(i).x;
        points[i].y = qFace.getPlane(i).z;
        points[i].z = -qFace.getPlane(i).y;
    }

    Vector3f normal;
    float distance = 0.0;

    findNormalFromPoints(points, normal, distance);

    Vector3f uVec, vVec;
    if (qFace.isValveFormat()) {
        alignTextureToFace(qFace, uVec, vVec);
    } else {
        alignTextureToWorld(normal, qFace.getRotation(), uVec, vVec);
    }

    gFace.setTextureName(qFace.getTextureName());
    gFace.setNormal(normal);
    gFace.setDistance(distance);

    // Apply light map scale while keeping original texture scale
    float scaleX = gFace.getScaleX() / qFace.getXLightMapScale();
    float scaleY = gFace.getScaleY() / qFace.getYLightMapScale();

    gFace.setVecU(uVec * scaleX);
    gFace.setVecV(vVec * scaleY);

    gFace.setScaleX(scaleX);
    gFace.setScaleY(scaleY);

    gFace.setOffsetX(qFace.getOffsetX());
    gFace.setOffsetY(qFace.getOffsetY());

    gFace.setFlags(qFace.getSurfaceFlags());

    gFace.setLightIntensity(qFace.getLightIntensity());
    gFace.setAlpha(static_cast<float>(qFace.getTransparencyValue()));
    gFace.setReflectivityScale(qFace.getReflectivityScale());
    gFace.setMipMapBias(qFace.getMipMapBias());

    return true;
}

bool QuakeToGenesis::findNormalFromPoints(const Vector3f points[3],
                                          Vector3f& normal,
                                          float& distance) {
    const int NumPoints = 3;  // 3 points per plane
    Vector3f v1, v2;

    int i = 0;
    while (i < NumPoints) {
        v1 = points[i] - points[(i + 1) % NumPoints];
        v2 = points[(i + 2) % NumPoints] - points[(i + 1) % NumPoints];
        normal = v1.crossProduct(v2);
        if (!normal.almostEqual(Vector3f(0.0f, 0.0f, 0.0f),
                                Vector3f::CompareEpsilon)) {
            break;
        }
        i++;
    }

    // Error: Face with no normal!
    if (i >= NumPoints) {
        return false;
    }

    normal.normalize();
    distance = points[1].dotProduct(normal);

    return true;
}

void QuakeToGenesis::alignTextureToWorld(Vector3f normal,
                                         float rotation,
                                         Vector3f& uVec,
                                         Vector3f& vVec) {
    const float Pi = 3.141592741f;

    float ang = (rotation * Pi) / 180.0f;  // degrees to radians
    float sinv = sin(ang);
    float cosv = cos(ang);

    int whichAxis = 0;
    if (fabs(normal.y) > fabs(normal.x)) {
        if (fabs(normal.z) > fabs(normal.y)) {
            whichAxis = 2;
        } else {
            whichAxis = 1;
        }
    } else if (fabs(normal.z) > fabs(normal.x)) {
        whichAxis = 2;
    }

    if (whichAxis == 0) {
        uVec = Vector3f(0.0f, sinv, -cosv);
        vVec = Vector3f(0.0f, -cosv, sinv);
    } else if (whichAxis == 1) {
        uVec = Vector3f(cosv, 0.0f, sinv);
        vVec = Vector3f(-sinv, 0.0f, cosv);
    } else if (whichAxis == 2) {
        uVec = Vector3f(cosv, sinv, 0.0f);
        vVec = Vector3f(sinv, -cosv, 0.0f);
    }
}

void QuakeToGenesis::alignTextureToFace(const QuakeFace& qFace,
                                        Vector3f& uVec,
                                        Vector3f& vVec) {
    // no need to do any calculations, level editor does this for us
    // we just need to convert the coordinate system
    uVec.x = qFace.getVecU().x;
    uVec.y = qFace.getVecU().z;
    uVec.z = -qFace.getVecU().y;

    vVec.x = qFace.getVecV().x;
    vVec.y = qFace.getVecV().z;
    vVec.z = -qFace.getVecV().y;
}

bool QuakeToGenesis::convertEnt(const QuakeEntity& qEnt, GenesisEntity& gEnt) {
    // Insert brushes to Genesis entity
    for (const auto& brush : qEnt.brushes()) {
        GenesisBrush gBrush;
        std::optional<int> contentFlags;
        for (const auto& face : brush.faces()) {
            GenesisFace gFace;
            convertFace(face, gFace);
            gBrush.insertFace(gFace);
            // Set content flags from the first face
            if (!contentFlags.has_value()) {
                contentFlags = face.getContentFlags();
            }
        }
        // Default content flags if none were set
        gBrush.setFlags(
            contentFlags.value_or(GenesisBrush::BrushContentFlags::Solid));
        gEnt.insertBrush(gBrush);
    }

    // Insert keyvalues to Genesis entity
    for (const auto& [key, value] : qEnt.properties()) {
        if (key == "classname" && value != "worldspawn") {
            gEnt.insertKeyValue("%name%", getNameForEntity(value));
        } else if (key == "origin") {
            Vector3f origin;
            if (convertCoords(value, origin)) {
                gEnt.insertKeyValue(
                    key, fmt::format("{} {} {}", origin.x, origin.y, origin.z));
                continue;
            }
            std::cerr << "Error converting origin to Genesis\n";
        } else {
            gEnt.insertKeyValue(key, value);
        }
    }

    return false;
}

std::string QuakeToGenesis::getNameForEntity(const std::string& classname) {
    // Every entity has a name assigned (light1, light2, etc...)
    // Generate those names automatically
    if (m_numEntsByClass.count(classname) == 0) {
        m_numEntsByClass.insert({classname, 0});
    }
    int num = m_numEntsByClass.at(classname);
    m_numEntsByClass.at(classname) = ++num;
    return classname + std::to_string(num);
}

bool QuakeToGenesis::convertCoords(const std::string& origin,
                                   Vector3f& vector) {
    StringTokenizer st = StringTokenizer(origin);

    if (st.countTokens() < 3) {
        return false;
    }
    Vector3f temp = {st.nextTokenFloat(), st.nextTokenFloat(),
                     st.nextTokenFloat()};
    vector.x = temp.x;
    vector.y = temp.z;
    vector.z = -temp.y;

    return true;
}