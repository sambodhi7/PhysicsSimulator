#include  "vector2.hpp"
#pragma once
class RigidBody{
    private : 
      Vector2 position ;
      float m_mass ;
      float m_onebymass; 
      float m_linVelocity ;
    public :
        RigidBody ( float mass, Vector2 pos ) ;
        void setMass ( float mass) ;
        float getMass () const ;
        Vector2 getPosition () const ;
        void setPosition ( Vector2 pos ) ;
        void applyForce ( Vector2 force, float dt ) ;


        
};