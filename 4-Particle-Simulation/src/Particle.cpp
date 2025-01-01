#include "Particle.h"

Particle::Particle(float x, float y, float radius) {
    shape.setPosition(x, y);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);
    
    // Initialize velocity and acceleration
    vx = vy = 0.0f;
    ax = 0.0f;  // No horizontal acceleration
    ay = 9.8f;  // Gravity
}

void Particle::update(float dt) {
    // Update velocity based on acceleration (gravity affects only the vertical velocity)
    vy += ay * dt;  // Gravity

    // Update position based on velocity
    shape.move(vx * dt, vy * dt);

    // Check for collision with the bottom of the window
    if (shape.getPosition().y + shape.getRadius() * 2 >= 600) {  // 600 is the height of the window
        vy = -vy * 0.9f;  // Reverse the vertical velocity (bounce) and apply a damping factor (0.9)
        shape.setPosition(shape.getPosition().x, 600 - shape.getRadius() * 2);  // Prevent particles from going below the bottom
    }
}
