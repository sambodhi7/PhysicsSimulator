#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Circle.hpp"
#include "PhysicsWorld.hpp"
#include "Vector2.hpp"
#include <SFML/Graphics.hpp>

namespace Demo {
    // Helper function to generate random float between min and max
    inline float randomFloat(float min, float max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen);
    }

   

    // Generate random circles for simulation
    inline std::vector<Circle*> generateRandom(int n, float windowWidth, float windowHeight) {
        std::vector<Circle*> circles;
        circles.reserve(n);

        const float MIN_RADIUS = 10.f;
        const float MAX_RADIUS = 30.f;
        const float MIN_MASS = 1.f;
        const float MAX_MASS = 5.f;
        const float MARGIN = MAX_RADIUS; // Keep circles away from walls

        for (int i = 0; i < n; ++i) {
            float radius = randomFloat(MIN_RADIUS, MAX_RADIUS);
            float mass = randomFloat(MIN_MASS, MAX_MASS);
            float x = randomFloat(MARGIN, windowWidth - MARGIN);
            float y = randomFloat(MARGIN, windowHeight - MARGIN);
            float e = randomFloat(0.7f, 1.0f);
            
            // Generate random velocity components directly for more uniform distribution
            float maxSpeed = 200.0f;  // Increased max speed
            float vx = randomFloat(-maxSpeed, maxSpeed);
            float vy = randomFloat(-maxSpeed, maxSpeed);

            RigidBody* rb = new RigidBody(mass, Vector2(x, y));
            rb->e = e;
            rb->setLinearVelocity(Vector2(vx, vy));
            
            Circle* c = new Circle(radius, rb);
          
            PhysicsWorld::getInstance().addComponent(c);
            PhysicsWorld::getInstance().addRigidBody(rb);
            circles.push_back(c);
        }
        return circles;
    }
}
