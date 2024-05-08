#include "Pokemon.h"
#include <iostream>

// Default constructor
Pokemon::Pokemon() : name("Unidentified"), hp(0), attack(0), defense(0) {
    std::cout << "Default Constructor (Pokemon)\n";
}

// Overloaded constructor
Pokemon::Pokemon(std::string name, int hp, int att, int def, std::vector<std::string> type) 
    : name(name), hp(hp), attack(att), defense(def), type(type) {
    std::cout << "Overloaded Constructor (Pokemon)\n";
}

// Print Pokemon stats
void Pokemon::printStats() const {
    std::cout << "Name: " << name << "\nHP: " << hp << " ATT: " << attack << " DEF: " << defense << "\nTypes: ";
    for (const auto& t : type) {
        std::cout << t << " ";
    }
    std::cout << std::endl;
}

// Pokemon speak
void Pokemon::speak() const {
    std::cout << "..." << std::endl;
}
