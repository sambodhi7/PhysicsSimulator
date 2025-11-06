#pragma once 
#include "RigidBody.hpp"
#include "Vector2.hpp"
#include "vector"
class CollisionManifold{
    private:
        RigidBody* m_A;
        RigidBody* m_B;
        Vector2 m_normal;
        float m_penetration=0.0f;
        std::vector<Vector2> m_contactPoints;
        bool m_isColliding = false;
    public : 
        CollisionManifold() : m_A(nullptr), m_B(nullptr), m_normal(Vector2()), m_penetration(0.0f), m_isColliding(false) {}
        CollisionManifold(RigidBody* a, RigidBody* b, Vector2 normal, float p );
        void addContactPoint(Vector2& point);
        Vector2 getNormal() ;
        std::vector<Vector2>& getContactPoints();
        float getPenetration();
        bool isColliding();      
        void applyPositionalCorrection();
        void applyImpulse();
};