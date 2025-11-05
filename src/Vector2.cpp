#include "Vector2.hpp"
Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}
Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}
Vector2 Vector2::operator*(const float scalar) const {
    return Vector2(x * scalar, y * scalar);
}
Vector2 Vector2::operator/(const float scalar) const {
    return Vector2(x / scalar, y / scalar);
}
Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}
Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
Vector2& Vector2::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}
Vector2& Vector2::operator/=(const float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
float Vector2::magnitude() const {
    return sqrt(x * x + y * y);
}
float Vector2::magnitudeSquared() const {
    return x * x + y * y;
}
Vector2 Vector2::normalized() const {
    float mag = magnitude();
    if (mag == 0) return Vector2(0, 0);
    return Vector2(x / mag, y / mag);
}   
void Vector2::normalize() {
    float mag = magnitude();
    if (mag != 0) {
        x /= mag;
        y /= mag;
    }
}
float Vector2::dot(const Vector2& other) const {
    return x * other.x + y * other.y;
}

float Vector2::angleBetween(const Vector2& other) const {
    float dotProd = dot(other);
    float mags = magnitude() * other.magnitude();
    if (mags == 0) return 0;
    float cos_theta = dotProd / mags;
    if(cos_theta > 1) cos_theta = 1;
    else if(cos_theta < -1) cos_theta = -1;
    return acos(cos_theta);
}

float Vector2::distanceTo(const Vector2& other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

float Vector2::distanceSquaredTo(const Vector2& other) const {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
}

bool Vector2::isZero() const {
    return x == 0 && y == 0;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}