#include "Charmander.h"
#include <iostream>

// Default constructor
Charmander::Charmander() : Pokemon("Unidentified", 0, 0, 0, {"Fire"}) {
    skills.push_back("Growl");
    skills.push_back("Scratch");
    std::cout << "Default Constructor (Charmander)\n";
}

// Overloaded constructor
Charmander::Charmander(std::string name, int hp, int att, int def, std::vector<std::string> type, std::vector<std::string> skills)
    : Pokemon(name, hp, att, def, type), skills(skills) {
    std::cout << "Overloaded Constructor (Charmander)\n";
}

// Print Charmander stats
void Charmander::printStats() const {
    Pokemon::printStats();  // Call base class function to print common stats
    std::cout << "Skills: ";
    for (const auto& skill : skills) {
        std::cout << skill << " ";
    }
    std::cout << std::endl;
}

// Charmander speak
void Charmander::speak() const {
    std::cout << "Charmander-char!\n";
}
