#include "Vector2.hpp"
#include "Shape.hpp"
#include "RigidBody.hpp"
#include "Component.hpp"
// circle header file no implementation
class Circle : public Shape, public Component
{
    private : 
        RigidBody* m_rb ;
        float m_radius; 
    public :
        Circle ( float r ) ; 
        Circle (float r, RigidBody* rb ) ;
        float getRadius () const ; 
        void setRadius ( float r ) ;
        Vector2 getCenter () const ;
        void setRigidBody ( RigidBody* rb ) ;
        RigidBody* getRigidBody () const ;
    
};