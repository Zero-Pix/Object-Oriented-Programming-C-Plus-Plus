#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>

class Pokemon {
private:
    std::string name;
    int hp;
    int attack;
    int defense;
    std::vector<std::string> type;

public:
    // Default constructor
    Pokemon();

    // Overloaded constructor
    Pokemon(std::string name, int hp, int att, int def, std::vector<std::string> type);

    // Method to print Pokemon stats
    void printStats() const;

    // Method for Pokemon to speak
    void speak() const;
};

#endif
