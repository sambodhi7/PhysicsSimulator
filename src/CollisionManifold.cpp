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

void CollisionManifold::applyPositionalCorrection() {
    const float percent = 0.2f;
    const float slop = 0.001f; 

    if (m_penetration <= slop) return;

    float onebymsum = 0.0f;
    if (!m_A->hasInfiniteMass()) onebymsum += m_A->onebym();
    if (!m_B->hasInfiniteMass()) onebymsum += m_B->onebym();
    if (onebymsum == 0.0f) return;

    Vector2 correction = m_normal * (m_penetration * percent / onebymsum);

    // clamp so it doesn't overshoot
    if (!m_A->hasInfiniteMass())
        m_A->setPosition(m_A->getPosition() - correction * m_A->onebym());
    if (!m_B->hasInfiniteMass())
        m_B->setPosition(m_B->getPosition() + correction * m_B->onebym());
}


void CollisionManifold::applyImpulse() {
    if (m_A->hasInfiniteMass() && m_B->hasInfiniteMass()) return;

    Vector2 relativeVelocity = m_B->getLinearVelocity() - m_A->getLinearVelocity();
    float normalVelocity = relativeVelocity.dot(m_normal);

    // Only resolve if bodies are moving toward each other
    if (normalVelocity > 0) return;

    float e = std::min(m_A->e, m_B->e); // restitution

    float j = -(1.0f + e) * normalVelocity;

    float onebymsum = 0.0f;
    if (!m_A->hasInfiniteMass()) onebymsum += m_A->onebym();
    if (!m_B->hasInfiniteMass()) onebymsum += m_B->onebym();
    if (onebymsum == 0.0f) return;

    j /= onebymsum;

    Vector2 impulse = m_normal * j;

    if (!m_A->hasInfiniteMass())
        m_A->applyImpulse(-impulse);
    if (!m_B->hasInfiniteMass())
        m_B->applyImpulse(impulse);

    // Optional: zero out any tiny penetrating velocity to prevent jitter
    const float slop = 0.01f;
    Vector2 vA = m_A->getLinearVelocity();
    Vector2 vB = m_B->getLinearVelocity();

    if (!m_A->hasInfiniteMass() && vA.dot(m_normal) < slop)
        vA -= m_normal * vA.dot(m_normal);
    if (!m_B->hasInfiniteMass() && vB.dot(m_normal) < slop)
        vB -= m_normal * vB.dot(m_normal);

    m_A->setLinearVelocity(vA);
    m_B->setLinearVelocity(vB);
}

