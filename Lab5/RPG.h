#ifndef RPG_H_
#define RPG_H_

#include <iostream>
#include <string>
#include <array>
using namespace std;


const int SKILL_SIZE = 2;

class RPG {
public:
    RPG();
    RPG(std::string name, int health, int strength, int defense, std::string type);

    // Member functions
    void setSkills();
    void printAction(std::string, RPG );
    void updateHealth(int );
    void attack(RPG*);
    void useSkill(RPG*);
    bool isAlive() const;
    std::string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;

private:
    std::string name;
    int strength;
    int health;
    int defense;
    std::string type;
    std::array<std::string, SKILL_SIZE> skills;
};

#endif // RPG_H_
