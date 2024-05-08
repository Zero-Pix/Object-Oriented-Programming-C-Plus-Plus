#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "Pokemon.h"
#include <vector>
#include <string>

class Charmander : public Pokemon {
private:
    std::vector<std::string> skills;

public:
    // Default constructor
    Charmander();

    // Overloaded constructor
    Charmander(std::string name, int hp, int att, int def, std::vector<std::string> type, std::vector<std::string> skills);

    // Method to print Charmander stats
    void printStats() const;

    // Method for Charmander to speak
    void speak() const;
};

#endif
