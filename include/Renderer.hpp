#pragma once
#include "Component.hpp"
#include <Circle.hpp>
#include <SFML/Graphics.hpp>
class Circle;

class Plane;
class Renderer
{   private : 
    sf::RenderWindow* m_window ;
    Renderer () {};
    public : 
        static Renderer& getInstance () ;
         void setRenderWindow ( sf::RenderWindow* window ) ;
         void render ( Component* comp ) ;
         void render ( Circle* circle ) ;
         void render ( Plane* plane ) ;
         
}; 
