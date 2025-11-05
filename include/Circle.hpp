#pragma once
#include "Vector2.hpp"
#include "Shape.hpp"
#include "RigidBody.hpp"
#include "Component.hpp"
#include "Renderer.hpp"
// circle header file no implementation
class Circle : public Component
{
    private : 
        
        float m_radius; 
        RigidBody* m_rb ;
    public :
        Circle ( float r ) ; 
        Circle (float r, RigidBody* rb ) ;
        float getRadius () const ; 
        void setRadius ( float r ) ;
        Vector2 getCenter () const ;
        void setRigidBody ( RigidBody* rb ) ;
        RigidBody* getRigidBody () const ;
        void render ( Renderer& renderer ) override ;
};