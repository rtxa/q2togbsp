#include <cmath>
#include "Vector3f.h"

Vector3f::Vector3f() : Vector3f(0.0f, 0.0f, 0.0f) {
}

Vector3f::Vector3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3f::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f Vector3f::operator + (const Vector3f& vector) const {
	return Vector3f(x + vector.x, y + vector.y, z + vector.z);
}

Vector3f Vector3f::operator - (const Vector3f& vector) const {
	return Vector3f(x - vector.x, y - vector.y, z - vector.z);
}

Vector3f Vector3f::operator * (float scale) const {
	return Vector3f(x * scale, y * scale, z * scale);
}

Vector3f Vector3f::operator / (float scale) const {
	return Vector3f(x / scale, y / scale, z / scale);
}

Vector3f Vector3f::crossProduct(const Vector3f& vector) const {
	return Vector3f(y * vector.z - z * vector.y,
					z * vector.x - x * vector.z,
					x * vector.y - y * vector.x);
}

float Vector3f::dotProduct(const Vector3f& vector) const {
	return (this->x * vector.x + y * vector.y + z * vector.z);
}

float Vector3f::length() const {
	return sqrt(x*x + y*y + z*z);
}

Vector3f Vector3f::operator - () const {
	return Vector3f(-x, -y, -z);
}

void Vector3f::opposite() {
	set(-x, -y, -z);
}

Vector3f Vector3f::normalized() const {
	const float distance = length();

	return Vector3f(x / distance, y / distance, z / distance);
}

void Vector3f::normalize() {
	const float distance = length();
	set(x / distance, y / distance, z / distance);
}

bool Vector3f::epsilonEquals(const Vector3f& vector, float epsilon) const {
	if (fabs(vector.x - x) > epsilon)
		return false;
	if (fabs(vector.y - y) > epsilon)
		return false;
	if (fabs(vector.z - z) > epsilon)
		return false;
	return true;
}
