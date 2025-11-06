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

sf::Color getColor(float m){
    switch( (int)m % 4){
        case 0: return sf::Color::Red;
        case 1: return sf::Color::Blue;
        case 2: return sf::Color::Green;
        case 3: return sf::Color::Yellow;
    }
}

void Renderer::render(Circle* circle) {
    
    Vector2 center = circle->getRigidBody()->getPosition();
    float radius = circle->getRadius();
    sf::CircleShape shape(radius);
    shape.setFillColor(getColor(circle->getRigidBody()->getMass()));
    shape.setOrigin({radius, radius});
    shape.setPosition({center.x, center.y});
    m_window->draw(shape);

}

void Renderer::render(Plane* plane){
    // Vector2 normal = plane->getNormal();
    // float offset = plane->getOffset();

    // Vector2 pointOnPlane = normal * offset;

    // Vector2 dir(-normal.y, normal.x); 

    // Vector2 lineStart = pointOnPlane - dir * 1000.0f; 
    // Vector2 lineEnd = pointOnPlane + dir * 1000.0f; 

    // sf::Vertex line[] =
    // {
    //     sf::Vertex(sf::Vector2f(lineStart.x, lineStart.y), sf::Color::Red),
    //     sf::Vertex(sf::Vector2f(lineEnd.x, lineEnd.y), sf::Color::Red)
    // };

    // m_window->draw(line, 2, sf::Lines);
}