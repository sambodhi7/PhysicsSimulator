#include "ForceRegistry.hpp"
#include <algorithm>

void ForceRegistry::add ( RigidBody* rb , ForceGenerator* fg ) {
    m_registrations.emplace_back ( rb , fg  ) ;
}
void ForceRegistry::remove ( RigidBody* rb , ForceGenerator* fg ) {
    m_registrations.erase ( std::remove_if ( m_registrations.begin() , m_registrations.end() ,
        [ rb , fg ] ( const ForceRegistration& reg ) {
            return reg.m_rb == rb && reg.m_fg == fg ;
        } ) , m_registrations.end() ) ;
}
void ForceRegistry::clear () {
    m_registrations.clear() ;
}
void ForceRegistry::updateForces ( float dt ) {
    for ( auto& reg : m_registrations ) {
        reg.m_fg->updateForce ( reg.m_rb , dt ) ;
    }
}

