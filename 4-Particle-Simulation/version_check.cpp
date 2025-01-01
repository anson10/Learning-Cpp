#include <SFML/Config.hpp>
#include <iostream>

int main() {
    std::cout << "SFML Version: " 
              << SFML_VERSION_MAJOR << "." 
              << SFML_VERSION_MINOR << "." 
              << SFML_VERSION_PATCH << std::endl;

    return 0;
}
