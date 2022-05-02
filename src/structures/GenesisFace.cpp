#include "GenesisFace.h"

#include <iostream>
#include <algorithm>

GenesisFace::GenesisFace() {
	m_flags = 0;
	m_mipMapBias = 1.0f;
	m_alpha = 255.0f;
	m_lightIntensity = 300;
	m_reflectivityScale = 1.0f;

	m_uVec = Vector3f(0.0f, 0.0f, 0.0f);
	m_vVec = Vector3f(0.0f, 0.0f, 0.0f);

	m_xScale = 1.0f;
	m_yScale = 1.0f;

	m_xOffset = 0.0f;
	m_yOffset = 0.0f;

	m_normal = Vector3f(0.0f, 0.0f, 0.0f);
	m_distance = 0.0f;
}

void GenesisFace::setFlags(int value) {
	m_flags = value;
}

void GenesisFace::setMipMapBias(float value) {
	m_mipMapBias = value;
}

void GenesisFace::setAlpha(float value) {
	m_alpha = value;
}

void GenesisFace::setLightIntensity(int value) {
	m_lightIntensity = value;
}

void GenesisFace::setTextureName(std::string name) {
	m_textureName = name;
}

void GenesisFace::setReflectivityScale(float value) {
	m_reflectivityScale = value;
}

void GenesisFace::setScaleX(float value) {
	m_xScale = value;
}

void GenesisFace::setScaleY(float value) {
	m_yScale = value;
}

void GenesisFace::setOffsetX(float value) {
	m_xOffset = value;
}

void GenesisFace::setOffsetY(float value) {
	m_yOffset = value;
}

void GenesisFace::setVecU(Vector3f point) {
	m_uVec = point;
}

void GenesisFace::setVecV(Vector3f point) {
	m_vVec = point;
}

void GenesisFace::setNormal(Vector3f normal) {
	m_normal = normal;
}

void GenesisFace::setDistance(float distance) {
	m_distance = distance;
}

int GenesisFace::getFlags() const {
	return m_flags;
}

float GenesisFace::getMipMapBias() const {
	return m_mipMapBias;
}

float GenesisFace::getAlpha() const {
	return m_alpha;
}

int GenesisFace::getLightIntensity() const {
	return m_lightIntensity;
}

std::string GenesisFace::getTextureName() const {
	return m_textureName;
}

float GenesisFace::getReflectivityScale() const {
	return m_reflectivityScale;
}

float GenesisFace::getScaleX() const {
	return m_xScale;
}

float GenesisFace::getScaleY() const {
	return m_yScale;
}

float GenesisFace::getOffsetX() const {
	return m_xOffset;
}
float GenesisFace::getOffsetY() const {
	return m_yOffset;
}

Vector3f GenesisFace::getVecU() const {
	return m_uVec;
}

Vector3f GenesisFace::getVecV() const {
	return m_vVec;
}

Vector3f GenesisFace::getNormal() const {
	return m_normal;
}

float GenesisFace::getDistance() const {
	return m_distance;
}

void GenesisFace::printFace() const {
	std::cout << "Face: ";
	std::cout << "Normal " << "[ " << m_normal.x << '\t' << m_normal.y << '\t' << m_normal.z << '\t' << m_distance << " ] ";
	std::cout << "TexName: " << m_textureName << " Scale X/Y " << m_xScale << ' ' << m_yScale;
	//std::cout << " Offset X/Y " << m_xOffset << ' ' << m_yOffset << " Rotation " << m_rotation;
	std::cout << '\n';

}