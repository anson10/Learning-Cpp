#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle {
public:
    sf::CircleShape shape;
    float vx, vy; // velocity components
    float ax, ay; // acceleration components
    float x, y;   // position
    float radius; // radius of the particle
    float mass;   // mass of the particle

    Particle(float x, float y, float radius, float mass, float vx = 0.0f, float vy = 0.0f);

    void update(float dt);
    bool checkCollision(const Particle& other) const;
    void resolveCollision(Particle& other);
};

#endif
