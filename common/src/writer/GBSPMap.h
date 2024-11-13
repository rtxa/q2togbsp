#pragma once

#include <cstdint>

#pragma pack(1)
struct FileHeader {
    std::int32_t version;
    char tag[4];
    std::int32_t numEntities;
};

struct BrushHeader {
    std::int32_t flags;
    std::int32_t numFaces;
};

struct FaceHeader {
    std::int32_t flags;
    float mipMapBias;
    float alpha;           // Alpha for brush (0-255)
    float lightIntensity;  // face light
    float reflectivityScale;
    char textureName[32];
    float uVecX, uVecY, uVecZ;
    float xScale, xOffset;
    float vVecX, vVecY, vVecZ;
    float yScale, yOffset;
    float normalX, normalY, normalZ;
    float distance;
};
#pragma pack()