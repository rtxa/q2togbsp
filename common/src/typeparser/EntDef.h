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
