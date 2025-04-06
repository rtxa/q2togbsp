#include "Vector3f.h"

#include <fmt/format.h>

#include <cmath>

void Vector3f::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f Vector3f::operator+(const Vector3f& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3f Vector3f::operator-(const Vector3f& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vector3f Vector3f::operator*(float scale) const {
    return {x * scale, y * scale, z * scale};
}

Vector3f Vector3f::operator/(float scale) const {
    return {x / scale, y / scale, z / scale};
}

Vector3f Vector3f::crossProduct(const Vector3f& other) const {
    return {y * other.z - z * other.y, z * other.x - x * other.z,
            x * other.y - y * other.x};
}

float Vector3f::dotProduct(const Vector3f& other) const {
    return (x * other.x + y * other.y + z * other.z);
}

float Vector3f::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3f Vector3f::operator-() const {
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

// Overloading the multiplication operator for matrix-vector multiplication
Vector3f Vector3f::operator*(const float matrix[3][3]) const {
    return Vector3f(matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z,
                    matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z,
                    matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z);
}

// Function to convert radians to degrees
float Vector3f::toDegrees(float radians) {
    const float M_PI = 3.141592741f;
    return radians * (180.0f / M_PI);
}
float Vector3f::toRadians(float degrees) {
    const float M_PI = 3.141592741f;
    return degrees * (M_PI / 180.0f);
}

std::string Vector3f::toString() const {
    return fmt::format("{} {} {}", x, y, z);
}