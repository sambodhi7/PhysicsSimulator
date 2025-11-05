#include "RigidBody.hpp"
class ForceGenerator{
    public :
        virtual void updateForce ( RigidBody* rb , float dt ) = 0 ; 
};
