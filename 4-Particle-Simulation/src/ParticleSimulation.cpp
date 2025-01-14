#include "ParticleSimulation.h"
#include <cmath>

ParticleSimulation::ParticleSimulation() : timeStep(0.016f) {}

void ParticleSimulation::addParticle(float x, float y, float radius, float mass, float vx, float vy) {
    particles.emplace_back(x, y, radius, mass, vx, vy);
}

void ParticleSimulation::update(float dt) {
    for (auto& particle : particles) {
        particle.update(dt);

        // Boundary collisions
        if (particle.x - particle.radius < 0) {
            particle.vx = -particle.vx;
            particle.x = particle.radius;
        }
        if (particle.x + particle.radius > 800) {  // Window width
            particle.vx = -particle.vx;
            particle.x = 800 - particle.radius;
        }
        if (particle.y - particle.radius < 0) {
            particle.vy = -particle.vy;
            particle.y = particle.radius;
        }
        if (particle.y + particle.radius > 600) {  // Window height
            particle.vy = -particle.vy * 0.9f;  // Damping effect
            particle.y = 600 - particle.radius;
        }
    }

    // Check and resolve collisions between particles
    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = i + 1; j < particles.size(); ++j) {
            if (particles[i].checkCollision(particles[j])) {
                particles[i].resolveCollision(particles[j]);
            }
        }
    }
}

void ParticleSimulation::render(sf::RenderWindow& window) {
    for (const auto& particle : particles) {
        window.draw(particle.shape);
    }
}
