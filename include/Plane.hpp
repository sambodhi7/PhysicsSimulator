#pragma once
#include "Component.hpp"
#include "Vector2.hpp"
#include "RigidBody.hpp"
#include "Renderer.hpp"

class Plane : public Component {
private:
    Vector2 m_normal;
    Vector2 m_point;
    RigidBody* m_rb;

public:
    Plane(const Vector2& normal, const Vector2& point)
        : Component(ColliderType::Plane), m_normal(normal), m_point(point) 
    {
        m_normal.normalize();
        m_rb = new RigidBody(0.0f, point); // infinite mass
    }

    Vector2 getNormal() const { return m_normal; }
    Vector2 getPoint() const { return m_point; }

    RigidBody* getRigidBody() { return m_rb; }

    void render(Renderer& renderer) { renderer.render(this); }


    void reflect(RigidBody* body) {
        Vector2 v = body->getLinearVelocity();
        float vn = v.dot(m_normal);
        if (vn < 0) { 
            Vector2 v_perp = m_normal * vn;
            Vector2 v_par = v - v_perp;
            body->setLinearVelocity(v_par - v_perp); 
        }
    }
};