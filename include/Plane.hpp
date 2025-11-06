#pragma once
#include "Component.hpp"
#include "Vector2.hpp"
#include "Renderer.hpp"
class Plane : public Component {
    private :
        Vector2 m_normal ;
        Vector2 m_point ;
        RigidBody* m_rb; 
    public :
        Plane (  Vector2& normal , Vector2 point ) 
            : Component ( ColliderType::Plane ) , m_normal ( normal ) , m_point ( point ) {
                m_normal . normalize () ;
                m_rb = new RigidBody(0.0f, point);
            } ;
        Vector2 getNormal ()  { return m_normal ; } ;
        Vector2 getPoint ()  { return m_point ; } ;
        void render ( Renderer& renderer ) { renderer.render ( this ) ; } ;
        RigidBody* getRigidBody(){return m_rb;}
};