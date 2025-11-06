#include "PhysicsWorld.hpp"

#include <iostream>
#include <Component.hpp>
#include "DownWardsGravity.hpp"
#include "Collisions.hpp"

PhysicsWorld& PhysicsWorld::getInstance() {
    static PhysicsWorld instance;
    return instance;
}

void PhysicsWorld::update(float dt) {
    if(!m_isRunning) return;

    m_forceRegister.updateForces(dt);
    for (RigidBody* rb : m_bodies) {
        rb->update(dt);
    }

    int n = m_components.size();
    std::vector<CollisionManifold> manifolds;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            Component* compA = m_components[i];
            Component* compB = m_components[j];

            if (!compA || !compB) continue;

            CollisionManifold manifold = Collisions::findCollisionFeatures(compA, compB);
            if (manifold.isColliding()) {
                manifolds.push_back(manifold);
            }
        }
    }

    const int collisionIterations = 10;
    for (int k = 0; k < collisionIterations; k++) {
        for (auto& manifold : manifolds) {
            manifold.applyImpulse();
            manifold.applyPositionalCorrection();
        }
    }
}


void PhysicsWorld::renderAll(Renderer& renderer) {
    for (Component* comp : m_components) {
        if (comp != nullptr) {
            renderer.render(comp);
        }
    }
}



void PhysicsWorld::addRigidBody ( RigidBody* rb ) {
    // apply gravity to the rigid body
    m_forceRegister.add ( rb , &DownWardsGravity::getInstance() ) ;
    m_bodies.push_back ( rb ) ;


}

void PhysicsWorld::addComponent ( Component* comp ) {
    m_components.push_back ( comp ) ;
}

void PhysicsWorld::pause(){
    m_isRunning = false;
}

void PhysicsWorld::resume(){
    m_isRunning = true;
}

void PhysicsWorld::toggleRunning(){
    m_isRunning = !m_isRunning; 
}

