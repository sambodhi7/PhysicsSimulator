#include "Component.hpp"
#include <Circle.hpp>
#include <SFML/Graphics.hpp>
class Renderer
{   private : 
    sf::RenderWindow* m_window ;
    Renderer () {};
    public : 
        static Renderer& getInstance () ;
         void setRenderWindow ( sf::RenderWindow* window ) ;
         void render ( Circle& circle ) ;
}; 
