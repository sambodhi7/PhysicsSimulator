#include <SFML/Graphics.hpp>
#include <optional>
#include "confg.hpp"
#include "utils.hpp"
#include "PhysicsWorld.hpp"
#include "addComponent.hpp"
#include "Renderer.hpp"
#include "Circle.hpp"
#include "RigidBody.hpp"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(sf::Vector2u(config::WINDOW_WIDTH, config::WINDOW_HEIGHT)),
        "Physics Simulator 2D",
        sf::Style::Titlebar | sf::Style::Close
    );

    PhysicsWorld& physicsWorld = PhysicsWorld::getInstance();
    Renderer::getInstance().setRenderWindow(&window);

    float accumulator = 0.0f;
    float prevTime   = utils::getCurrentTimeInSeconds();


    Circle* c = new Circle(10.0f, new RigidBody(1.0f, Vector2(100.0f, 100.0f)));
    physicsWorld.addComponent(c);

    while (window.isOpen())
    {
        float currentTime = utils::getCurrentTimeInSeconds();
        float frameTime   = currentTime - prevTime;
        prevTime          = currentTime;
        accumulator      += frameTime;

        while (accumulator >= config::FIXED_DT)
        {
            physicsWorld.update(config::FIXED_DT);
            accumulator -= config::FIXED_DT;
        }

        
        while (auto event = window.pollEvent())
        {
          
            if (event->is<sf::Event::Closed>())
                window.close();

           
            if (auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouse->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    add::createCircle(
                        15.0f,
                        static_cast<float>(mousePos.x),
                        static_cast<float>(mousePos.y),
                        1.0f
                    );
                }   
            }
        }

        window.clear(sf::Color(50, 50, 50));
        physicsWorld.renderAll(Renderer::getInstance());
        
        window.display();
    }

    return 0;
}
