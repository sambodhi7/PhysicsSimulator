#include<iostream>
#include<math.h>
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2{
    public :
    float  x, y;
    
    Vector2(float x=0, float y=0) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const ;

    Vector2 operator-(const Vector2& other) const ;

    Vector2 operator*(const int scalar) const ;

    Vector2 operator/(const int scalar) const ;
    
    Vector2& operator+=(const Vector2& other) ;
    Vector2& operator-=(const Vector2& other) ;
    Vector2& operator*=(const float scalar) ;
    Vector2& operator/=(const float scalar) ;

    float magnitude() const ;
    float magnitudeSquared() const ;
    Vector2 normalized() const ;
    void normalize() ;
    float dot(const Vector2& other) const ;
    float angleBetween(const Vector2& other) const ;
    float distanceTo(const Vector2& other) const ;
    float distanceSquaredTo(const Vector2& other) const ;
    bool isZero() const ;

    friend std::ostream& operator<<(std::ostream& os, const Vector2& vec)  ;

};



#endif // VECTOR2_HPP