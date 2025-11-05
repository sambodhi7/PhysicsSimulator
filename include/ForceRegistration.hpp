#include "rigidbody.hpp"

class ForceRegistration {
    public :
        RigidBody* m_rb ; 
        ForceGenerator* m_fg ; 
        ForceRegistration ( RigidBody* rb , ForceGenerator* fg ) : m_rb ( rb ) , m_fg ( fg ) {}
}