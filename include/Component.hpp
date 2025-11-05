#pragma once
class Renderer ;
class Component {
    public :
        virtual ~Component(); 
        virtual void render ( Renderer& renderer ) =0 ;
};

