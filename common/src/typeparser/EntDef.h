#pragma once

#include <string>
#include <vector>

struct EntDefProp {
    EntDefProp()
        : isPublished(false),
          isOrigin(false),
          isAngles(false),
          isArc(false),
          isRadius(false) {}

    std::string type;
    std::string name;
    std::string defaultValue;
    std::string documentation;
    bool isPublished;
    bool isOrigin;
    bool isAngles;
    bool isRadius;
    bool isArc;
};

struct EntDef {
    std::string typeIcon;  // GE_Type
    std::string name;      // Entity classname
    std::vector<EntDefProp> properties;
};

namespace EntDefType {
constexpr auto WorldModel = "geWorld_Model*";
constexpr auto Color = "GE_RGBA";
constexpr auto Boolean = "geBoolean";
constexpr auto Integer = "int";
constexpr auto Float = "float";
constexpr auto GeFloat = "geFloat";
constexpr auto Point = "geVec3d";
constexpr auto String = "char*";
}  // namespace EntDefType