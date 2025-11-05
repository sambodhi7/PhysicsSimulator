
#pragma once
// singleton class that manages the physics simulation 
#include "Renderer.hpp"
#include "RigidBody.hpp"
#include "Component.hpp"
#include<vector>

class PhysicsWorld
{
    private :  
     PhysicsWorld () {};
     std::vector<RigidBody*> m_bodies ; 
     std::vector<Component*> m_components ; 


   public : 
     static PhysicsWorld& getInstance(); 
     void update ( float dt) ;
     void renderAll(Renderer& renderer);
      void addRigidBody ( RigidBody* rb ) ;
      void addComponent ( Component* comp ) ;

};
