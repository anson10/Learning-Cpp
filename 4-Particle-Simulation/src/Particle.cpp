#include "Particle.h"
#include <cmath>

Particle::Particle(float x, float y, float radius, float mass, float vx, float vy)
    : x(x), y(y), radius(radius), mass(mass), vx(vx), vy(vy), ax(0.0f), ay(9.8f) {  // Gravity
    shape.setPosition(x, y);
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setFillColor(sf::Color::White);
}

void Particle::update(float dt) {
    // Apply acceleration to velocity
    vx += ax * dt;
    vy += ay * dt;

    // Update position
    x += vx * dt;
    y += vy * dt;

    // Update shape position
    shape.setPosition(x, y);

    // Calculate speed and update color
    float speed = std::sqrt(vx * vx + vy * vy);
    sf::Uint8 red = static_cast<sf::Uint8>(std::min(255.0f, speed * 10.0f));  // Red increases with speed
    sf::Uint8 green = static_cast<sf::Uint8>(std::max(0.0f, 255.0f - speed * 5.0f));  // Green decreases with speed
    sf::Uint8 blue = static_cast<sf::Uint8>(50 + (std::rand() % 50));  // Add some randomness to blue

    shape.setFillColor(sf::Color(red, green, blue));
}


bool Particle::checkCollision(const Particle& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance < (radius + other.radius);
}

void Particle::resolveCollision(Particle& other) {
    float dx = other.x - x;
    float dy = other.y - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // Ensure particles are not overlapping
    if (distance == 0.0f) return;

    // Normal vector
    float nx = dx / distance;
    float ny = dy / distance;

    // Tangent vector
    float tx = -ny;
    float ty = nx;

    // Dot products of velocity with normal and tangent vectors
    float v1n = vx * nx + vy * ny;
    float v1t = vx * tx + vy * ty;
    float v2n = other.vx * nx + other.vy * ny;
    float v2t = other.vx * tx + other.vy * ty;

    // Conservation of momentum in 1D
    float v1n_after = (v1n * (mass - other.mass) + 2 * other.mass * v2n) / (mass + other.mass);
    float v2n_after = (v2n * (other.mass - mass) + 2 * mass * v1n) / (mass + other.mass);

    // Update velocities
    vx = v1n_after * nx + v1t * tx;
    vy = v1n_after * ny + v1t * ty;
    other.vx = v2n_after * nx + v2t * tx;
    other.vy = v2n_after * ny + v2t * ty;

    // Adjust positions to resolve overlap
    float overlap = radius + other.radius - distance;
    x -= overlap * nx / 2;
    y -= overlap * ny / 2;
    other.x += overlap * nx / 2;
    other.y += overlap * ny / 2;

    shape.setPosition(x, y);
    other.shape.setPosition(other.x, other.y);
}
