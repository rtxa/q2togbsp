#include "GenesisFace.h"

#include <fmt/format.h>

#include <iostream>
#include <algorithm>

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

void GenesisFace::setTextureName(const std::string& name) {
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

std::string GenesisFace::toString() const {
	return fmt::format("Plane: [{:<9} {:<9} {:<9} {:<9}] TexName: '{}' Scale X/Y: [{}, {}] Offset X/Y: [{}, {}] Flags: {} LightIntensity: {} Transparency: {} ReflectivityScale: {}  MipMapBias: {}", 
	m_normal.x, m_normal.y, m_normal.z, m_distance, m_textureName, m_xScale, m_yScale, m_xOffset, m_yOffset, m_flags, m_lightIntensity, m_alpha, m_reflectivityScale, m_mipMapBias);
}