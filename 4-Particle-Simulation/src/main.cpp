#include <SFML/Graphics.hpp>
#include "ParticleSimulation.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle Simulation");

    // Create a simulation instance
    ParticleSimulation simulation;

    // Add multiple particles with different initial positions, masses, and velocities
    simulation.addParticle(400, 300, 10, 1.0f, 0.0f, 0.0f);  // Center
    simulation.addParticle(100, 100, 10, 1.5f, 50.0f, 50.0f);  // Top-left
    simulation.addParticle(700, 200, 10, 2.0f, -30.0f, 70.0f);  // Right side
    simulation.addParticle(300, 500, 10, 1.0f, 0.0f, -40.0f);  // Bottom-left
    simulation.addParticle(300, 500, 10, 1.0f, 0.0f, -40.0f);  // Bottom-left

    simulation.addParticle(432, 203, 10, 1.1f, 20.0f, -15.0f);
simulation.addParticle(320, 50, 10, 1.4f, -60.0f, 80.0f);
simulation.addParticle(720, 540, 10, 1.6f, -30.0f, -20.0f);
simulation.addParticle(420, 460, 10, 2.0f, 10.0f, -50.0f);
simulation.addParticle(540, 320, 10, 1.9f, -40.0f, 90.0f);
simulation.addParticle(150, 370, 10, 1.3f, 50.0f, -60.0f);
simulation.addParticle(670, 250, 10, 1.8f, -70.0f, 40.0f);
simulation.addParticle(380, 120, 10, 1.7f, 30.0f, -30.0f);
simulation.addParticle(590, 490, 10, 2.1f, -20.0f, 60.0f);
simulation.addParticle(260, 430, 10, 1.2f, 40.0f, 10.0f);
simulation.addParticle(650, 310, 10, 2.3f, 20.0f, -70.0f);
simulation.addParticle(70, 280, 10, 1.5f, 60.0f, 20.0f);
simulation.addParticle(740, 520, 10, 1.8f, -80.0f, 30.0f);
simulation.addParticle(240, 130, 10, 1.0f, 30.0f, 50.0f);
simulation.addParticle(360, 570, 10, 2.0f, 50.0f, -40.0f);
simulation.addParticle(440, 330, 10, 1.2f, -60.0f, -10.0f);
simulation.addParticle(570, 250, 10, 1.6f, -10.0f, 70.0f);
simulation.addParticle(320, 410, 10, 1.7f, 60.0f, 30.0f);
simulation.addParticle(430, 350, 10, 1.3f, -30.0f, -60.0f);
simulation.addParticle(660, 510, 10, 2.4f, -20.0f, 80.0f);
simulation.addParticle(260, 250, 10, 2.1f, 40.0f, -10.0f);
simulation.addParticle(120, 160, 10, 1.2f, 70.0f, -50.0f);
simulation.addParticle(700, 50, 10, 2.0f, 20.0f, 40.0f);
simulation.addParticle(180, 300, 10, 1.8f, 30.0f, -30.0f);
simulation.addParticle(560, 540, 10, 1.5f, -60.0f, 60.0f);
simulation.addParticle(50, 450, 10, 1.1f, 50.0f, 50.0f);
simulation.addParticle(670, 130, 10, 1.7f, -40.0f, 70.0f);
simulation.addParticle(420, 190, 10, 2.2f, 20.0f, -20.0f);
simulation.addParticle(330, 490, 10, 1.3f, -50.0f, -60.0f);
simulation.addParticle(250, 550, 10, 1.9f, 30.0f, 50.0f);
simulation.addParticle(510, 380, 10, 2.3f, 40.0f, -10.0f);
simulation.addParticle(550, 100, 10, 1.4f, -20.0f, 80.0f);
simulation.addParticle(680, 170, 10, 2.0f, 70.0f, -40.0f);
simulation.addParticle(340, 150, 10, 1.8f, -10.0f, 60.0f);
simulation.addParticle(590, 220, 10, 1.5f, 50.0f, 20.0f);
simulation.addParticle(410, 560, 10, 1.6f, -30.0f, 10.0f);
simulation.addParticle(690, 90, 10, 1.2f, -20.0f, 50.0f);
simulation.addParticle(230, 250, 10, 1.9f, 40.0f, 40.0f);
simulation.addParticle(360, 130, 10, 2.1f, 60.0f, -30.0f);
simulation.addParticle(470, 380, 10, 2.0f, 30.0f, 70.0f);
simulation.addParticle(330, 270, 10, 1.8f, -40.0f, 20.0f);
simulation.addParticle(450, 140, 10, 1.4f, 50.0f, -50.0f);
simulation.addParticle(260, 320, 10, 1.2f, 60.0f, 60.0f);
simulation.addParticle(600, 470, 10, 1.5f, -60.0f, -10.0f);
simulation.addParticle(650, 430, 10, 2.0f, 40.0f, 30.0f);
simulation.addParticle(150, 530, 10, 2.3f, -50.0f, 10.0f);
simulation.addParticle(700, 370, 10, 1.6f, 20.0f, 40.0f);
simulation.addParticle(540, 400, 10, 2.4f, -10.0f, -20.0f);
simulation.addParticle(380, 80, 10, 1.5f, 70.0f, 30.0f);
simulation.addParticle(230, 430, 10, 1.2f, 30.0f, -60.0f);
simulation.addParticle(150, 100, 10, 1.8f, -70.0f, 40.0f);
simulation.addParticle(500, 320, 10, 1.9f, 40.0f, 20.0f);
simulation.addParticle(320, 560, 10, 1.7f, 50.0f, -50.0f);
simulation.addParticle(200, 240, 10, 2.2f, 60.0f, 30.0f);
simulation.addParticle(410, 510, 10, 2.0f, -30.0f, 60.0f);
simulation.addParticle(340, 200, 10, 1.6f, 20.0f, -40.0f);
simulation.addParticle(660, 440, 10, 1.9f, -50.0f, 20.0f);
simulation.addParticle(280, 120, 10, 1.3f, 40.0f, 50.0f);


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

        // Update simulation
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
