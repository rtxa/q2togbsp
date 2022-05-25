// Thanks to https://efxa.org/2018/07/14/a-simple-3d-vector-prototype-library/

#pragma once

#include <string>

class Vector3f {
public:
	static constexpr float CompareEpsilon = 0.001f; // this should go in Constants.h

	float x {0.0f};
	float y {0.0f};
	float z {0.0f};

	Vector3f() = default;
	Vector3f(float x, float y, float z) : x{x}, y{y}, z{z} {};

	void set(float x, float y, float z);

	Vector3f operator + (const Vector3f& vector) const;
	Vector3f operator - (const Vector3f& vector) const;
	Vector3f operator * (float scale) const;
	Vector3f operator / (float scale) const;

	Vector3f crossProduct(const Vector3f& vector) const;
	float dotProduct(const Vector3f& vector) const;
	
	float length() const;

	Vector3f operator - () const;
	void opposite();

	Vector3f normalized() const;
	void normalize();

	bool epsilonEquals(const Vector3f& vector, float epsilon) const;

	std::string toString() const;
};
