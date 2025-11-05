#include "RigidBody.hpp"
#include "Vector2.hpp"
RigidBody::RigidBody ( float mass, Vector2 pos ) 
    : m_mass ( mass ), position ( pos ) {
    if ( mass == 0 ) {
        m_onebymass = 0 ; 
    } else {
        m_onebymass = 1.0f / mass ; 
    }
    m_linVelocity = 0.0f ;
}

bool RigidBody::hasInfiniteMass() const {
    return m_mass==0;
}

void RigidBody::setMass ( float mass) {
    m_mass = mass ;
    if ( mass == 0 ) {
        m_onebymass = 0 ; 
    } else {
        m_onebymass = 1.0f / mass ; 
    }
}
float RigidBody::getMass () const {
    return m_mass ;
}

Vector2 RigidBody::getPosition () const {
    return position ;
}
void RigidBody::setPosition ( Vector2 pos ) {
    position = pos ;
}

void RigidBody::applyForce(Vector2 force ){
    m_sigmaforce += force ;
}

// Eucledian integration will replace later 
void RigidBody::update (float dt) { 
    Vector2 acceleration = m_sigmaforce * m_onebymass;
    m_linVelocity = m_linVelocity +  (acceleration * dt * 0.5f);
    position += m_linVelocity * dt;
    m_linVelocity = m_linVelocity +  (acceleration * dt * 0.5f);
    m_sigmaforce = Vector2 (0.0f, 0.0f); 
}

