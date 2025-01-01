# Particle Simulation in C++ with SFML

This project simulates particles that fall due to gravity and bounce when they hit the bottom of the window. The simulation is created using C++ and SFML (Simple and Fast Multimedia Library).

## Features:
- Multiple particles with different starting positions.
- Gravity affects the particles, causing them to fall.
- Particles bounce when they hit the bottom of the window.
- Real-time simulation with smooth animation.

## Prerequisites:

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).
- **CMake**: Version 3.10 or higher.
- **SFML**: The project uses the SFML library for graphics, window management, and input handling.

### On Linux:
You can install SFML using the following command:
```bash
sudo apt-get install libsfml-dev
```

### On Windows (via vcpkg or similar package manager):
Follow instructions from the [SFML official website](https://www.sfml-dev.org/download.php) or install it via `vcpkg`.

## Setting up the project:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/anson10/4-Particle-Simulation.git
    cd Particle-Simulation
    ```

2. **Create a build directory**:
    ```bash
    mkdir build
    cd build
    ```

3. **Run CMake to configure the project**:
    ```bash
    cmake ..
    ```

4. **Build the project using `make`**:
    ```bash
    make
    ```

5. **Run the simulation**:
    ```bash
    ./ParticleSimulation
    ```

## Project Structure:
- `src/`: Contains the main source code files (`main.cpp`, `Particle.cpp`, `ParticleSimulation.cpp`).
- `include/`: Contains header files (`Particle.h`, `ParticleSimulation.h`).
- `CMakeLists.txt`: CMake configuration file.

## Notes:
- The simulation creates several particles that are affected by gravity and will bounce once they hit the bottom of the window.
- Feel free to modify the code, add features, or create your own particle behaviors!

---
