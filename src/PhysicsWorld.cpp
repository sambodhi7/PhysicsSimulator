#include "PhysicsWorld.hpp"

#include <iostream>
#include <Component.hpp>
PhysicsWorld& PhysicsWorld::getInstance() {
    static PhysicsWorld instance;
    return instance;
}

void PhysicsWorld::update ( float dt) {
    
}

void PhysicsWorld::renderAll(Renderer& renderer) {
    for (Component* comp : m_components) {
        if (comp != nullptr) {
            renderer.render(comp);
        }
    }
}



void PhysicsWorld::addRigidBody ( RigidBody* rb ) {
    m_bodies.push_back ( rb ) ;
}

void PhysicsWorld::addComponent ( Component* comp ) {
    m_components.push_back ( comp ) ;
}
