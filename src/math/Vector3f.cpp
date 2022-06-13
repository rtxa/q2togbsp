#include "Vector3f.h"

#include <fmt/format.h>

#include <cmath>

void Vector3f::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f Vector3f::operator + (const Vector3f& vector) const {
	return {x + vector.x, y + vector.y, z + vector.z};
}

Vector3f Vector3f::operator - (const Vector3f& vector) const {
	return {x - vector.x, y - vector.y, z - vector.z};
}

Vector3f Vector3f::operator * (float scale) const {
	return {x * scale, y * scale, z * scale};
}

Vector3f Vector3f::operator / (float scale) const {
	return {x / scale, y / scale, z / scale};
}

Vector3f Vector3f::crossProduct(const Vector3f& vector) const {
	return {y * vector.z - z * vector.y,
			z * vector.x - x * vector.z,
			x * vector.y - y * vector.x};
}

float Vector3f::dotProduct(const Vector3f& vector) const {
	return (this->x * vector.x + y * vector.y + z * vector.z);
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
	const float distance = length();

	return {x / distance, y / distance, z / distance};
}

void Vector3f::normalize() {
	const float distance = length();
	set(x / distance, y / distance, z / distance);
}

bool Vector3f::almostEqual(const Vector3f& vector, float tolerance) const {
    return std::fabs(x - vector.x) < tolerance &&
    	   std::fabs(y - vector.y) < tolerance &&
           std::fabs(z - vector.z) < tolerance;
}

std::string Vector3f::toString() const {
	return fmt::format("{} {} {}", x, y, z);
}