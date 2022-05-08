#pragma once

#include <string>

#include "math/Vector3f.h"

class QuakeFace {
public:
	void setOffsetX(float value);
	void setOffsetY(float value);
	void setRotation(float value);
	void setScaleX(float value);
	void setScaleY(float value);
	void setPlane(Vector3f point1, Vector3f point2, Vector3f point3);
	void setTextureName(const std::string& name);
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
	float m_xOffset{0.0f};
	float m_yOffset{0.0f};
	float m_rotation{0.0f};
	float m_xScale{0.0f};
	float m_yScale{0.0f};
	int m_surfaceFlags{0};
	int m_contentFlags{0};
	int m_lightIntensity{0};
	std::string m_textureName; // TODO maybe i should use char[32] or an std::array
};
