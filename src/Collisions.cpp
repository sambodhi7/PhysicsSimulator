#include "Collisions.hpp"
#include "Plane.hpp"
#include "Circle.hpp"
#include "RigidBody.hpp"

CollisionManifold Collisions::findCollisionFeatures(Component* c1, Component* c2) {
    if (c1->m_colliderType == ColliderType::Circle && c2->m_colliderType == ColliderType::Circle) {
        return findCollisionFeatures(static_cast<Circle*>(c1), static_cast<Circle*>(c2));
    }
    else if (c1->m_colliderType == ColliderType::Circle && c2->m_colliderType == ColliderType::Plane) {
        return findPlaneCollisionFeatures(static_cast<Circle*>(c1), static_cast<Plane*>(c2));
    }
    else if (c1->m_colliderType == ColliderType::Plane && c2->m_colliderType == ColliderType::Circle) {
        return findPlaneCollisionFeatures(static_cast<Circle*>(c2), static_cast<Plane*>(c1));
    }
    return CollisionManifold();
}

CollisionManifold Collisions::findPlaneCollisionFeatures(Circle* circle, Plane* plane) {
    if (!circle || !plane || !circle->getRigidBody()) return CollisionManifold();

    Vector2 circleCenter = circle->getCenter();
    float radius = circle->getRadius();
    Vector2 planeNormal = plane->getNormal();
    Vector2 planePoint = plane->getPoint();

    Vector2 toCircle = circleCenter - planePoint;
    float distance = toCircle.dot(planeNormal);

    if (distance < radius) { 
        plane->reflect(circle->getRigidBody()); // simple reflection
        // optional: reposition circle so it does not sink
        Vector2 correction = planeNormal * (radius - distance);
        circle->getRigidBody()->setPosition(circle->getRigidBody()->getPosition() + correction);
    }

    return CollisionManifold(); // empty because impulse is handled
}


CollisionManifold Collisions::findCollisionFeatures(Circle* a, Circle* b) {
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