#pragma once

// Thanks to https://efxa.org/2018/07/14/a-simple-3d-vector-prototype-library/

class Vector3f {
public:
	static constexpr float CompareEpsilon = 0.001f; // this should go in Constants.h
	float x, y, z;

public:
	Vector3f();

	Vector3f(const float x, const float y, const float z);

	void set(const float x, const float y, const float z);

	Vector3f operator + (const Vector3f & vector) const;

	Vector3f operator - (const Vector3f & vector) const;

	Vector3f operator * (const float scale) const;

	Vector3f operator / (const float scale) const;

	Vector3f crossProduct(const Vector3f & vector) const;

	float dotProduct(const Vector3f & vector) const;

	float length() const;

	Vector3f operator - () const;

	void opposite ();

	Vector3f normalized() const;

	void normalize();

	bool epsilonEquals(const Vector3f & vector, float epsilon) const;
};
