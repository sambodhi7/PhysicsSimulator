#include "Circle.hpp"

Circle::Circle(float r) : radius(r) {
    m_rb = nullptr;
}

Circle::Circle(float r, RigidBody* rb) : radius(r), m_rb(rb) {
}

float Circle::getRadius() const {
     return radius; }

void Circle::setRadius(float r) { 
    radius = r; }

Vector2 Circle::getCenter() const { 
    return ,m_rb->getPosition(); }

void Circle::setRigidBody(RigidBody* rb) { 
    m_rb = rb; }

RigidBody* Circle::getRigidBody() const { 
    return m_rb; }




