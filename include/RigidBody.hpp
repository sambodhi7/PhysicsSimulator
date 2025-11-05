#include  "vector2.hpp"
#pragma once
class RigidBody{
    private : 
      
      float m_mass ;
      float m_onebymass; 
      Vector2 m_linVelocity ;
      Vector2 m_sigmaforce;
      Vector2 position ;

      
    public :
        RigidBody ( float mass, Vector2 pos ) ;
        void setMass ( float mass) ;
        float getMass () const ;
        Vector2 getPosition () const ;
        void setPosition ( Vector2 pos ) ;
        void applyForce ( Vector2 force, float dt ) ;
        void update ( float dt ) ;
        void applyForce( Vector2 force ) ;
        bool hasInfiniteMass() const ; 
        
};