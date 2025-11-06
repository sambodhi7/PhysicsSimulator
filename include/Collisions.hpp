#pragma once
#include "Component.hpp"
#include "Circle.hpp"
#include "CollisionManifold.hpp"
#include "Vector2.hpp"

class Collisions {
public:
    static CollisionManifold findCollisionFeatures(Component* c1, Component* c2) {
        if (c1->m_colliderType == ColliderType::Circle && c2->m_colliderType == ColliderType::Circle) {
            return findCollisionFeatures(static_cast<Circle*>(c1), static_cast<Circle*>(c2));
        }
        return CollisionManifold();
    }

    static CollisionManifold findCollisionFeatures(Circle* a, Circle* b) {
        if (!a || !b || !a->getRigidBody() || !b->getRigidBody()) {
            return CollisionManifold();
        }

        float sumRadii = a->getRadius() + b->getRadius();
        Vector2 distance = b->getCenter() - a->getCenter();
        
        if (distance.magnitudeSquared() - (sumRadii * sumRadii) > 0) {
            return CollisionManifold();
        }

        float depth = std::abs(distance.magnitude() - sumRadii) * 0.5f;
        Vector2 normal = distance.normalized();
        float distanceToPoint = a->getRadius() - depth;
        Vector2 contactPoint = a->getCenter() + normal * distanceToPoint;

        CollisionManifold result(a->getRigidBody(), b->getRigidBody(), normal, depth);
        result.addContactPoint(contactPoint);
        return result;
    }
};