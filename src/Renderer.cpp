#include "Renderer.hpp"
#include "Circle.hpp"
#include "Vector2.hpp"
#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include <iostream>
Renderer& Renderer::getInstance() {
    static Renderer instance;
    return instance;
}

void Renderer::setRenderWindow(sf::RenderWindow* window) {
    m_window = window;
}

void Renderer::render(Component* comp) {
    
    comp->render(*this);
    
}

void Renderer::render(Circle* circle) {
    
    Vector2 center = circle->getRigidBody()->getPosition();
    float radius = circle->getRadius();
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({radius, radius});
    shape.setPosition({center.x, center.y});
    m_window->draw(shape);

}