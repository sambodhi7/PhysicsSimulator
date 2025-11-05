#pragma once
#include <vector>
#include<ForceRegistration.hpp>
#include <vector>
#include <algorithm>
class ForceRegistry {
    private :
     std::vector<ForceRegistration> m_registrations ;
    public :
        void add ( RigidBody* rb , ForceGenerator* fg ) ;
        void remove ( RigidBody* rb , ForceGenerator* fg ) ;
        void clear () ;
        void updateForces ( float dt ) ;
};