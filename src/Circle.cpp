#include "Circle.hpp"
#include "Renderer.hpp"

Circle::Circle(float r) 
    : Component(ColliderType::Circle), m_radius(r), m_rb(nullptr) 
    {}
Circle::Circle(float r, RigidBody* rb) 
    : Component(ColliderType::Circle), m_radius(r), m_rb(rb) 
    {}

float Circle::getRadius() const {
     return m_radius; }

void Circle::setRadius(float r) { 
    m_radius = r; }

Vector2 Circle::getCenter() const { 
    return m_rb->getPosition(); }

void Circle::setRigidBody(RigidBody* rb) { 
    m_rb = rb; }

RigidBody* Circle::getRigidBody() const { 
    return m_rb; }

void Circle::render(Renderer& renderer) {
    renderer.render(this);
}



