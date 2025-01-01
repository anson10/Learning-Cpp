#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Particle.h"
#include "ParticleSimulation.h"
int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle Simulation");

    // Create a simulation instance
    ParticleSimulation simulation;

    // Add multiple particles with different initial positions
    simulation.addParticle(400, 300, 10);  // Particle at the center
    simulation.addParticle(100, 100, 10);  // Particle at a different position
    simulation.addParticle(700, 200, 10);  // Another particle
    simulation.addParticle(300, 500, 10);  // Particle near the bottom

    // Clock for timing
    sf::Clock clock;

    // Main loop
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update simulation (this applies movement to particles)
        simulation.update(dt);

        // Clear the window
        window.clear();

        // Render particles
        simulation.render(window);

        // Display the contents of the window
        window.display();
    }

    return 0;
}

