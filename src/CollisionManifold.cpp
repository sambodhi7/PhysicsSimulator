#include "CollisionManifold.hpp"
#include "RigidBody.hpp"
#include "Vector2.hpp"


CollisionManifold::CollisionManifold(RigidBody* a, RigidBody* b, Vector2 normal, float p )
    : m_A(a), m_B(b), m_normal(normal), m_penetration(p), m_isColliding(true) {
}
void CollisionManifold::addContactPoint(Vector2& point) {
    m_contactPoints.push_back(point);
}
Vector2 CollisionManifold::getNormal() {
    return m_normal;
}
std::vector<Vector2>& CollisionManifold::getContactPoints() {
    return m_contactPoints;
}
float CollisionManifold::getPenetration() {
    return m_penetration;
}
bool CollisionManifold::isColliding() {
    return m_isColliding;
}

void CollisionManifold::applyPositionalCorrection(){
    const float percent = 0.8f;
    float onebymsum = m_A->onebym() + m_B->onebym();
    if(onebymsum==0) return ;
    Vector2 correction = m_normal * (m_penetration * percent / onebymsum);
    m_A->setPosition(m_A->getPosition()- correction*m_A->onebym());
    m_B->setPosition(m_B->getPosition()+ correction*m_B->onebym());
}

void CollisionManifold::applyImpulse() {
   
    if (m_A->hasInfiniteMass() && m_B->hasInfiniteMass()) return;

    
    Vector2 relativeVelocity = m_B->getLinearVelocity() - m_A->getLinearVelocity();
    
    
    float normalVelocity = relativeVelocity.dot(m_normal);
    
   
    if (normalVelocity > 0) return;
    
    
    float e = std::min(m_A->e, m_B->e);
    
    float j = -(1.0f + e) * normalVelocity;
    float onebymsum = m_A->onebym() + m_B->onebym();
    if (onebymsum == 0) return; 
    j /= onebymsum;
    
  
    Vector2 impulse = m_normal * j;
    
   
    m_A->applyImpulse(impulse * -1.0f);
    m_B->applyImpulse(impulse);
}