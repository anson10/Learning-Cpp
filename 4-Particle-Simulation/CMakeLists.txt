cmake_minimum_required(VERSION 3.10)

# Project information
project(ParticleSimulation)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find SFML package
find_package(SFML 2.5 REQUIRED graphics window system)

# Add source files
set(SOURCES
    src/main.cpp
    src/Particle.cpp
    src/ParticleSimulation.cpp
)

# Create the executable
add_executable(ParticleSimulation ${SOURCES})

# Link SFML libraries
target_link_libraries(ParticleSimulation sfml-graphics sfml-window sfml-system)
