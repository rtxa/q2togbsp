#include "QuakeFace.h"

#include <fmt/format.h>

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

void QuakeFace::setTransparencyValue(int value) {
    m_transparencyValue = value;
}

void QuakeFace::setReflectivityScale(float value) {
    m_reflectivityScale = value;
}

void QuakeFace::setXLightMapScale(float value) {
    m_xLightMapScale = value;
}

void QuakeFace::setYLightMapScale(float value) {
    m_yLightMapScale = value;
}

void QuakeFace::setMipMapBias(float value) {
    m_mipMapBias = value;
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

int QuakeFace::getTransparencyValue() const {
    return m_transparencyValue;
}

float QuakeFace::getReflectivityScale() const {
    return m_reflectivityScale;
}

float QuakeFace::getXLightMapScale() const {
    return m_xLightMapScale;
}

float QuakeFace::getYLightMapScale() const {
    return m_yLightMapScale;
}

float QuakeFace::getMipMapBias() const {
    return m_mipMapBias;
}

std::string QuakeFace::toString() const {
	return fmt::format("Plane: ( {} ) ( {} ) ( {} ) TexName: {} Scale X/Y: {} {} Offset X/Y: {} {} Rotation: {} ContentFlags: {} SurfaceFlags: {} LightIntensity: {} TransparencyValue: {} ReflectivityScale: {} XLightMapScale: {} YLightMapScale: {} MipMapBias: {}", 
					    m_point1.toString(), m_point2.toString(), m_point3.toString(),
					    getTextureName(), getScaleX(), getScaleY(), getOffsetX(), getOffsetY(), getRotation(), getContentFlags(), getSurfaceFlags(), getLightIntensity(), getTransparencyValue(), getReflectivityScale(), getXLightMapScale(), getYLightMapScale(), getMipMapBias());													
}