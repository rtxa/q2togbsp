#pragma once

#include "math/Vector3f.h"

#include <string>

class GenesisFace {
	// TODO anyway this doesn't matter too much, this is Engine dependant and the code for converting doesn't care about this, editor must implement a different flag according to the engine
	// TexFlags is just everything about a face, that could be shared with another face or more...
	enum class TexFlags : int {
		Mirror = (1 << 0),				// This face is a mirror face
		FullBright = (1 << 1),			// This face is fully bright
		Sky = (1 << 2),					// This face is a sky portal
		Light = (1 << 3),				// This face emits light
		Translucent = (1 << 4),			// A hint to the engine, that this face is not solid 
		Gouraud = (1 << 5),				// This face is gouraud shaded
		Flat = (1 << 6),				// This face is flat shaded
		NoLightMap = (1 << 15)			// This face does not have a lightmap
	};

public:
	std::string toString() const;

	int getFlags() const;
	float getMipMapBias() const;
	float getAlpha() const;
	int getLightIntensity() const; // gbsp expects a float
	std::string getTextureName() const;
	float getReflectivityScale() const;
	float getScaleX() const;
	float getScaleY() const;
	float getOffsetX() const;
	float getOffsetY() const;
	Vector3f getVecU() const;
	Vector3f getVecV() const;
	Vector3f getNormal() const;
	float getDistance() const;

	void setFlags(int value);
	void setMipMapBias(float value); // not implemented
	void setAlpha(float value); // value is between 0-255
	void setLightIntensity(int value);
	void setTextureName(const std::string& name);
	void setReflectivityScale(float value);
	void setScaleX(float value);
	void setScaleY(float value);
	void setOffsetX(float value);
	void setOffsetY(float value);
	void setVecU(Vector3f point);
	void setVecV(Vector3f point);
	void setNormal(Vector3f normal);
	void setDistance(float distance);

private:
	int m_flags{0};
	float m_mipMapBias{1.0f};
	float m_alpha{255.0f};
	int m_lightIntensity{300};
	float m_reflectivityScale{1.0f};
	std::string m_textureName; 	// texture name max char is 32
	Vector3f m_uVec;
	Vector3f m_vVec;
	float m_xScale{1.0f};
	float m_yScale{1.0f};
	float m_xOffset{0.0f};
	float m_yOffset{0.0f};
	// Plane (Normal and distance)
	Vector3f m_normal;
	float m_distance{0.0f};
};

