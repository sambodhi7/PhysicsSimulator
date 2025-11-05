#include "RigidBody.hpp"

RigidBody::RigidBody ( float mass, Vector2 pos ) 
    : m_mass ( mass ), position ( pos ) {
    if ( mass == 0 ) {
        m_onebymass = 0 ; 
    } else {
        m_onebymass = 1.0f / mass ; 
    }
    m_linVelocity = 0.0f ;
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


