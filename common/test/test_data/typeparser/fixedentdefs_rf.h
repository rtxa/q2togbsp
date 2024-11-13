// Light
#pragma GE_Type("BMP_LIGHT")
typedef struct tag_light {
#pragma GE_Published
    int light;
    GE_RGBA color;
    int style;
    geVec3d origin;
#pragma GE_Origin(origin)
#pragma GE_DefaultValue(light, "150")
} light;
// SpotLight
#pragma GE_Type("BMP_SPOTLIGHT")
typedef struct tag_spotlight {
    int DummyRadius;
#pragma GE_Published
    int light;
    GE_RGBA color;
    int style;
    geVec3d origin;
    geVec3d angles;
    int arc;
#pragma GE_Origin(origin)
#pragma GE_Radius(DummyRadius)
#pragma GE_DefaultValue(DummyRadius, "150")
#pragma GE_DefaultValue(light, "150")
#pragma GE_Angles(angles)
#pragma GE_DefaultValue(angles, "0 0 0")
#pragma GE_Arc(arc)
#pragma GE_DefaultValue(arc, "45")
} spotlight;
//	Sunlight
#pragma GE_Type("BMP_SUNENTITY")
typedef struct tag_Sunlight {
#pragma GE_Published
    geVec3d origin;
    GE_RGBA color;
    int light;
    geVec3d angles;
    int style;
#pragma GE_Origin(origin)
#pragma GE_Angles(angles)
#pragma GE_DefaultValue(light, "150")
#pragma GE_DefaultValue(angles, "0 0 0")
#pragma GE_Documentation(color, "Color of the primary star or moon")
#pragma GE_Documentation(light, "Intensity - Only shines through SKY faces")
#pragma GE_Documentation(angles, "Direction of  sunlight flow")
#pragma GE_Documentation(style, "Use 0 for now. No other styles available.")
} Sunlight;
// Model origin
#pragma GE_Type("BMP_MODELORG")
typedef struct tag_ModelOrigin {
    geVec3d origin;
#pragma GE_Origin(origin)
} ModelOrigin;
// Camera
#pragma GE_Type("BMP_CAMERA")
typedef struct tag_Camera {
    geVec3d origin;
    geVec3d angles;
#pragma GE_Origin(origin)
#pragma GE_Angles(angles)
#pragma GE_DefaultValue(angles, "180 0 0")
} Camera;
