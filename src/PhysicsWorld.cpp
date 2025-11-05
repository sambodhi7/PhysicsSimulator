#include "PhysicsWorld.hpp"

PhysicsWorld::getInstance() {
    static PhysicsWorld instance;
    return instance;
}

void PhysicsWorld::update ( float dt) {
    // update all rigid bodies and apply forces
}


