#include "RigidBody.hpp"

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
