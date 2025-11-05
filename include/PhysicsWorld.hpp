
#pragma once
// singleton class that manages the physics simulation 
#include "Renderer.hpp"
#include "RigidBody.hpp"
#include "Component.hpp"
#include<vector>
#include "ForceRegistry.hpp"
#include "DownWardsGravity.hpp"

class PhysicsWorld
{
    private :  
     PhysicsWorld () {
       m_isRunning = true;
     };
     std::vector<RigidBody*> m_bodies ; 
     std::vector<Component*> m_components ; 
     ForceRegistry m_forceRegister ;
     bool m_isRunning = true;



   public : 
     static PhysicsWorld& getInstance(); 
     void update ( float dt) ;
     void renderAll(Renderer& renderer);
      void addRigidBody ( RigidBody* rb ) ;
      void addComponent ( Component* comp ) ;
      void pause();
      void resume();
      void toggleRunning();
      


};
