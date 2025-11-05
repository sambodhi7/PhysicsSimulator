#include  "vector2.hpp"

class RigidBody{
    private : 
      Vector2 position ;
      float m_mass ;
      float m_onebymass; 
      float m_linVelocity ;
    public :
        void setMass ( float mass) ;
        float getMass () const ;


        
};