#include  "vector2.hpp"
#pragma once
class RigidBody{
    private : 
      
      float m_mass ;
      float m_onebymass; 
      Vector2 m_linVelocity ;
      Vector2 m_sigmaforce;
      Vector2 position ;
      float m_angle;
      float m_angularVelocity ;
      float m_sigmaTorque ;
      

      
    public :
        float e=1.0f;  // Coefficient of restitution
        RigidBody ( float mass, Vector2 pos ) ;
        void setMass ( float mass) ;
        float getMass () const ;
        Vector2 getPosition () const ;
        void setPosition ( Vector2 pos ) ;
        void applyForce ( Vector2 force, float dt ) ;
        void update ( float dt ) ;
        void applyForce( Vector2 force ) ;
        bool hasInfiniteMass() const ; 
        float onebym() { return m_onebymass ; }
        
        
        Vector2 getLinearVelocity() const { return m_linVelocity; }
        void setLinearVelocity(const Vector2& vel) { m_linVelocity = vel; }
        
        
        void applyImpulse(const Vector2& impulse) {
            if (!hasInfiniteMass()) {
                m_linVelocity += impulse * m_onebymass;
            }
        }
};