#ifndef PARTICLESIMULATION_H
#define PARTICLESIMULATION_H

#include "Particle.h"
#include <vector>
#include <SFML/Graphics.hpp>

class ParticleSimulation {
public:
    std::vector<Particle> particles;
    float timeStep;

    ParticleSimulation();
    void addParticle(float x, float y, float radius);
    void update(float dt);
    void render(sf::RenderWindow& window);
};

#endif // PARTICLESIMULATION_H
