#include <SFML/Graphics.hpp>
#include <optional>
#include "confg.hpp"
#include "utils.hpp"
#include "PhysicsWorld.hpp"

int main()
{

   

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(config::WINDOW_WIDTH, config::WINDOW_HEIGHT)), "SFML Test", sf::Style::Titlebar | sf::Style::Close);
    
    window.setTitle("Physics Simulator 2D");

    PhysicsWorld& physicsWorld = PhysicsWorld::getInstance();
   
    float accumulator = 0.0f;
    float prevTime = utils::getCurrentTimeInSeconds();

   
    while (window.isOpen())
    {
        
        float currentTime = utils::getCurrentTimeInSeconds();
        float frameTime = currentTime - prevTime;
        prevTime = currentTime;
        accumulator += frameTime;
        while (accumulator >= config::FIXED_DT)
        {
            physicsWorld.update(config::FIXED_DT);
            accumulator -= config::FIXED_DT;s
        }


        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        window.clear(sf::Color(50, 50, 50));
        physicsWorld.renderAll(Renderer::getInstance());
        window.display();
    }

    return 0;
}
