#include "QuakeToGenesis.h"

#include "utils/StringTokenizer.h"

#include <fmt/format.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <optional>

GenesisMap QuakeToGenesis::convert(const QuakeMap& qMap,
                                   std::vector<EntDef>& entDefs) {
    GenesisMap gMap;

    for (const auto& ent : qMap.entities()) {
        GenesisEntity gEnt;
        convertEnt(ent, gEnt, entDefs);
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

// Provides default value for entity type in case is missing in header file
std::string getDefaultValueForType(const EntDefProp& prop) {
    if (prop.type == EntDefType::Color) {
        return "255 255 255";
    } else if (prop.type == EntDefType::Integer) {
        return "0";
    } else if (prop.type == EntDefType::Boolean) {
        return "0";
    } else if (prop.type == EntDefType::Float ||
               prop.type == EntDefType::GeFloat) {
        return "0.0";
    } else if (prop.type == EntDefType::Point) {
        return "0 0 0";
    } else if (prop.type == EntDefType::String) {
        return "";
    }

    return "";
}

// Currently, world models and user-defined structs can't be exported to the map
// if not set, doesn't matter if it's empty, it will crash the engine.
bool isPropertyStruct(const EntDefProp& prop) {
    if (prop.type == "int" || prop.type == "geBoolean") {
        return false;
    } else if (prop.type == "GE_RGBA") {
        return false;
    } else if (prop.type == "geFloat" || prop.type == "float") {
        return false;
    } else if (prop.type == "geWorld_Model*") {
        return true;
    } else if (prop.type == "geVec3d") {
        return false;
    } else if (prop.type == "char*") {
        return false;
    }
    return true;
}

bool parseVector(const std::string& input, Vector3f& vector) {
    auto st = StringTokenizer(input);
    if (st.countTokens() < 3) {
        return false;
    }
    vector.x = st.nextTokenFloat();
    vector.y = st.nextTokenFloat();
    vector.z = st.nextTokenFloat();
    return true;
}

bool QuakeToGenesis::convertEnt(const QuakeEntity& qEnt,
                                GenesisEntity& gEnt,
                                const std::vector<EntDef>& entDefs) {
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

    if (qEnt.properties().count("classname") == 0) {
        std::cerr << "Error: Entity has no classname\n";
        return false;
    }

    // Add worldspawn entity
    if (qEnt.properties().at("classname") == "worldspawn") {
        for (const auto& [key, value] : qEnt.properties()) {
            gEnt.insertKeyValue(key, value);
        }
    } else {  // Add entity classname and derived name
        gEnt.insertKeyValue("classname", qEnt.properties().at("classname"));
        gEnt.insertKeyValue(
            "%name%",
            qEnt.properties().count("%name%") != 0
                ? qEnt.properties().at("%name%")
                : getNameForEntity(qEnt.properties().at("classname")));
    }

    // Iterate through entity definitions
    for (const auto& entDef : entDefs) {
        if (entDef.name == qEnt.properties().at("classname")) {
            // Insert keyvalues from entity definition
            updateEntFromDefinition(qEnt, gEnt, entDef);
        }
    }

    return true;
}
// clang-format off
struct Matrix3x3 {
    float m[3][3];

    // Constructor to initialize the rotation matrix for Z-up to Y-up
    Matrix3x3() {
        // This matrix rotates around the X-axis (pitch)
        m[0][0] = 1.0f;     m[0][1] = 0.0f;      m[0][2] = 0.0f;
        m[1][0] = 0.0f;     m[1][1] = 0.0f;      m[1][2] = -1.0f; // Swap Y and Z
        m[2][0] = 0.0f;     m[2][1] = 1.0f;      m[2][2] = 0.0f;
    }
    
    // Multiply a vector by the matrix
    Vector3f operator*(const Vector3f& v) const {
        Vector3f result;
        result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
        result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
        result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;
        return result;
    }
};
// clang-format on

// Vector3f convertZUpToYUp(const Vector3f& zUpAngles) {
//     float zPitch = zUpAngles.y;  // Pitch around Y
//     float zYaw = zUpAngles.x;    // Yaw around Z
//     float zRoll = zUpAngles.z;   // Roll around X

//     // Convert to Y-up angles
//     float yUpPitch = -zYaw;  // Pitch becomes -Yaw
//     float yUpYaw = zPitch;   // Yaw becomes Pitch
//     float yUpRoll = zRoll;   // Roll remains the same

//     return Vector3f(yUpYaw, yUpPitch, yUpRoll);
// }

Vector3f multiplyMatrix(const float matrix[3][3], const Vector3f& vector) {
    Vector3f result;
    result.x = matrix[0][0] * vector.x + matrix[0][1] * vector.y +
               matrix[0][2] * vector.z;
    result.y = matrix[1][0] * vector.x + matrix[1][1] * vector.y +
               matrix[1][2] * vector.z;
    result.z = matrix[2][0] * vector.x + matrix[2][1] * vector.y +
               matrix[2][2] * vector.z;
    return result;
}

// Function to convert Z-UP to Y-UP
Vector3f convertZUpToYUp(const Vector3f& angles) {
    // Convert degrees to radians
    float pitchRad = Vector3f::toRadians(angles.x);
    float yawRad = Vector3f::toRadians(angles.y);
    float rollRad = Vector3f::toRadians(angles.z);

    // Rotation matrix for converting Z-UP to Y-UP (Z, Y, -X)
    float rotationMatrix[3][3] = {
        {0, 0, 1},   // New pitch
        {0, 1, 0},   // Roll inverted
        {-1, 0, 0},  // Yaw remains the same
    };

    // Original rotation vector
    Vector3f original(pitchRad, yawRad, rollRad);

    // Apply the rotation
    Vector3f rotated = multiplyMatrix(rotationMatrix, original);

    // Convert back to degrees
    return Vector3f(Vector3f::toDegrees(rotated.x),
                    Vector3f::toDegrees(rotated.y),
                    Vector3f::toDegrees(rotated.z));
}

void QuakeToGenesis::updateEntFromDefinition(const QuakeEntity& qEnt,
                                             GenesisEntity& gEnt,
                                             const EntDef& entDef) {
    for (const auto& prop : entDef.properties) {
        if (!prop.isPublished) {
            continue;
        }

        auto lower = prop.name;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        // Check if property exists (origin is a special case)
        auto propertyExists =
            qEnt.properties().count(lower) > 0 ||
            qEnt.properties().count(prop.name) > 0 ||
            (prop.isOrigin && qEnt.properties().count("origin") > 0);

        // Add missing properties
        if (!propertyExists) {
            if (isPropertyStruct(prop)) {
                continue;  // Skip missing world models or structs
            }
            // Insert default value if none is provided in entity definition
            auto value = prop.defaultValue.empty()
                             ? getDefaultValueForType(prop)
                             : prop.defaultValue;
            gEnt.insertKeyValue(prop.name, value);
            continue;
        }

        // Handle existing properties
        if (isPropertyStruct(prop) && qEnt.properties().at(prop.name).empty()) {
            continue;  // Skip empty world models or structs
        }

        // Do conversions
        if (prop.isOrigin) {
            Vector3f origin;
            if (convertCoords(qEnt.properties().at("origin"), origin)) {
                gEnt.insertKeyValue(prop.name, origin.toString());
            }
            continue;
        } else if (prop.name == "ActorRotation" || prop.name == "Orientation" ||
                   prop.name == "Orientacion" || prop.name == "Orientacion_1" ||
                   prop.name == "Orientacion_3" || prop.name == "angles" ||
                   prop.name == "Angles" || prop.name == "Angle" ||
                   prop.name == "Angulo") {
            // Hardcoded conversion of rotation for now
            if (prop.type == EntDefType::Point) {
                Vector3f angles;
                parseVector(qEnt.properties().at(prop.name), angles);
                gEnt.insertKeyValue(prop.name,
                                    convertZUpToYUp(angles).toString());

            } else if (prop.type == EntDefType::Float ||
                       prop.type == EntDefType::GeFloat) {
                // Float angle
                gEnt.insertKeyValue(prop.name, qEnt.properties().at(prop.name));
            }
        } else {  // Normal property, no conversion need it
            gEnt.insertKeyValue(prop.name, qEnt.properties().at(prop.name));
        }
    }
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
    Vector3f temp;
    parseVector(origin, temp);
    vector.x = temp.x;
    vector.y = temp.z;
    vector.z = -temp.y;

    return true;
}