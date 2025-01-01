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

ParticleSimulation::ParticleSimulation() : timeStep(0.016f) {}

void ParticleSimulation::addParticle(float x, float y, float radius) {
    particles.emplace_back(x, y, radius);
}

void ParticleSimulation::update(float dt) {
    // Loop over each particle and update its position
    for (auto& particle : particles) {
        particle.update(dt);
    }
}

void ParticleSimulation::render(sf::RenderWindow& window) {
    for (auto& particle : particles) {
        window.draw(particle.shape);
    }
}
