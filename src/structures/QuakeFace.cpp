#include "QuakeFace.h"
#include <iostream>

void QuakeFace::setOffsetX(float value) {
	m_xOffset = value;
}

void QuakeFace::setOffsetY(float value) {
	m_yOffset = value;
}

void QuakeFace::setRotation(float value) {
	m_rotation = value;
}

void QuakeFace::setScaleX(float value) {
	m_xScale = value;
}

void QuakeFace::setScaleY(float value) {
	m_yScale = value;
}
void QuakeFace::setPlane(Vector3f point1, Vector3f point2, Vector3f point3) {
	m_point1 = point1;
	m_point2 = point2;
	m_point3 = point3;
}

void QuakeFace::setTextureName(const std::string& name) {
	m_textureName = name;
}

void QuakeFace::setContentFlags(int flags){
	m_contentFlags = flags;
}

void QuakeFace::setSurfaceFlags(int flags) {
	m_surfaceFlags = flags;
}

void QuakeFace::setLightIntensity(int value) {
	m_lightIntensity = value;
}

float QuakeFace::getOffsetX() const {
	return m_xOffset;
}

float QuakeFace::getOffsetY() const {
	return m_yOffset;
}

float QuakeFace::getRotation() const {
	return m_rotation;
}

float QuakeFace::getScaleX() const {
	return m_xScale;
}

float QuakeFace::getScaleY() const {
	return m_yScale;
}

Vector3f QuakeFace::getPlane(const int index) const {
	switch (index) {
		case 0: return m_point1;
		case 1: return m_point2;
		case 2: return m_point3;
	}
	return Vector3f(0.0f, 0.0f, 0.0f);
}

std::string QuakeFace::getTextureName() const {
	return m_textureName;
}

int QuakeFace::getContentFlags() const {
	return m_contentFlags;
}

int QuakeFace::getSurfaceFlags() const {
	return m_surfaceFlags;
}

int QuakeFace::getLightIntensity() const {
	return m_lightIntensity;
}

void QuakeFace::printFace() const {
	Vector3f point;
	std::cout << "Face: ";
	for (int i = 0; i < 3; i++) {
		point = getPlane(i);
		std::cout << "( " << point.x << ' ' << point.y << ' ' << point.z << " ) ";
	}
	std::cout << "TexName: " << m_textureName << " Scale X/Y " << m_xScale << ' ' << m_yScale;
	std::cout << " Offset X/Y " << m_xOffset << ' ' << m_yOffset << " Rotation " << m_rotation;
	std::cout << '\n';
}