#pragma once
#include "Component.hpp"
#include "Circle.hpp"
#include "CollisionManifold.hpp"
#include "Vector2.hpp"

class Collisions {
public:
    static CollisionManifold findCollisionFeatures(Component* c1, Component* c2);
    static CollisionManifold findPlaneCollisionFeatures(Circle* circle, Plane* plane);
    static CollisionManifold findCollisionFeatures(Circle* a, Circle* b);
};
