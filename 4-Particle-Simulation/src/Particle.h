#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle
{
    public:
    sf::CircleShape shape;
    float vx, vy; //velocity components
    float ax, ay; //acceleration components

    Particle(float x, float y, float radius);

    void update(float dt);
};

#endif 