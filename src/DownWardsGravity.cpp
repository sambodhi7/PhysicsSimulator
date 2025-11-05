#include "DownWardsGravity.hpp"
#include "RigidBody.hpp"

DownWardsGravity::DownWardsGravity( ) 
    : m_gravity ( Vector2 ( 0.0f, 9.81f ) ) {
}

void DownWardsGravity::updateForce(RigidBody* rb , float dt){
    rb->applyForce( m_gravity * rb->getMass());
}