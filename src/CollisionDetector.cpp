#include "CollisionDetector.hpp"
#include "Circle.hpp"
#include "Plane.hpp"
bool CollisionDetector::detectCollision(Component* a, Component* b) {
    if (a->m_colliderType == ColliderType::Circle && b->m_colliderType == ColliderType::Circle) {
        return circleVsCircle(static_cast<Circle*>(a), static_cast<Circle*>(b));
    }
    else if (a->m_colliderType == ColliderType::Circle && b->m_colliderType == ColliderType::Plane) {
        return circleVsPlane(static_cast<Circle*>(a), static_cast<Plane*>(b));
    }
    else if (a->m_colliderType == ColliderType::Plane && b->m_colliderType == ColliderType::Circle) {
        return circleVsPlane(static_cast<Circle*>(b), static_cast<Plane*>(a));
    }
    return false;
}

bool CollisionDetector::circleVsCircle(Circle* a, Circle* b) {
    Vector2 centerA = a->getCenter();
    Vector2 centerB = b->getCenter();
    float radiusA = a->getRadius();
    float radiusB = b->getRadius();

    Vector2 diff = centerB - centerA;
    float distSq = diff.magnitudeSquared();
    float radiusSum = radiusA + radiusB;
    return distSq <= (radiusSum * radiusSum);
}

bool CollisionDetector::circleVsPlane(Circle* a, Plane* b) {
    Vector2 center = a->getCenter();
    float radius = a->getRadius();

    
  
    Vector2 planeNormal = b->getNormal();
    Vector2 planePoint = b->getPoint();

    
    
    Vector2 toCenter = center - planePoint;
    float distance = toCenter.dot(planeNormal);

    
    
    return std::abs(distance) <= radius;
}