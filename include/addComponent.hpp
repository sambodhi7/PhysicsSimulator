#pragma once
#include<Circle.hpp>
#include<RigidBody.hpp>
#include<PhysicsWorld.hpp>

namespace add{
    
     Circle* createCircle (float radius, float x, float y, float mass){
        RigidBody* rb = new RigidBody ( mass, Vector2 ( x, y ) ) ;
        Circle* circle = new Circle ( radius, rb ) ;
        PhysicsWorld::getInstance().addComponent ( circle ) ;
        PhysicsWorld::getInstance().addRigidBody ( rb ) ;
        return circle ;
     }
}