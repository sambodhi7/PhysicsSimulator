#pragma once
class Renderer ;

enum class ColliderType {
    None,
    Circle,
    Plane
};

class Component {
    public :
        Component ( ColliderType type ) : m_colliderType ( type ) {} ;
        ColliderType m_colliderType ;
        virtual ~Component(); 
        virtual void render ( Renderer& renderer ) =0 ;
};

