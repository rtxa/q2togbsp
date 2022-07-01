#include "Vector3f.h"

#include <fmt/format.h>

#include <cmath>

void Vector3f::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f Vector3f::operator + (const Vector3f& other) const {
	return {x + other.x, y + other.y, z + other.z};
}

Vector3f Vector3f::operator - (const Vector3f& other) const {
	return {x - other.x, y - other.y, z - other.z};
}

Vector3f Vector3f::operator * (float scale) const {
	return {x * scale, y * scale, z * scale};
}

Vector3f Vector3f::operator / (float scale) const {
	return {x / scale, y / scale, z / scale};
}

Vector3f Vector3f::crossProduct(const Vector3f& other) const {
	return {y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x};
}

float Vector3f::dotProduct(const Vector3f& other) const {
	return (x * other.x + y * other.y + z * other.z);
}

float Vector3f::length() const {
	return sqrt(x*x + y*y + z*z);
}

Vector3f Vector3f::operator - () const {
	return {-x, -y, -z};
}

void Vector3f::opposite() {
	set(-x, -y, -z);
}

Vector3f Vector3f::normalized() const {
	float distance = length();
	return {x / distance, y / distance, z / distance};
}

void Vector3f::normalize() {
	float distance = length();
	set(x / distance, y / distance, z / distance);
}

bool Vector3f::almostEqual(const Vector3f& other, float tolerance) const {
    return std::fabs(x - other.x) < tolerance &&
    	   std::fabs(y - other.y) < tolerance &&
           std::fabs(z - other.z) < tolerance;
}

std::string Vector3f::toString() const {
	return fmt::format("{} {} {}", x, y, z);
}