#pragma once
#include "ForceGenerator.hpp"
#include "Vector2.hpp" 

class DownWardsGravity : public ForceGenerator {
    private : 
        Vector2 m_gravity ;
               
         DownWardsGravity( );
    public : 
         static DownWardsGravity& getInstance() {
             static DownWardsGravity instance;
             return instance;
         }
         void updateForce(RigidBody* rb, float dt ) override ;

};