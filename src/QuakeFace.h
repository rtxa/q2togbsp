#pragma once

#include "Vector3f.h"
#include <string>

class QuakeFace {
public:
	QuakeFace();

	void setOffsetX(const float value);
	void setOffsetY(const float value);
	void setRotation(const float value);
	void setScaleX(const float value);
	void setScaleY(const float value);
	void setPlane(const Vector3f point1, const Vector3f point2, const Vector3f point3);
	void setTextureName(const std::string name);
	void setContentFlags(int flags);
	void setSurfaceFlags(int flags);
	void setLightIntensity(int value);

	float getOffsetX() const;
	float getOffsetY() const;
	float getRotation() const;
	float getScaleX() const;
	float getScaleY() const;
	Vector3f getPlane(int index) const;
	std::string getTextureName() const;
	int getContentFlags() const;
	int getSurfaceFlags() const;
	int getLightIntensity() const;

	void printFace() const;
private:
	// plane
	Vector3f m_point1;
	Vector3f m_point2;
	Vector3f m_point3;
	float m_xOffset;
	float m_yOffset;
	float m_rotation;
	float m_xScale;
	float m_yScale;
	int m_surfaceFlags;
	int m_contentFlags;
	int m_lightIntensity;
	std::string m_textureName; // TODO maybe i should use char[32] or an std::array
};
