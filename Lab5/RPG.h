#ifndef RPG_H_
#define RPG_H_

#include <string>
#include <array>

const int SKILL_SIZE = 2;

class RPG {
public:
    RPG();
    RPG(std::string name, int health, int strength, int defence, std::string type);

    // Member functions
    void setSkills();
    void printAction(std::string action, RPG target);
    void updateHealth(int healthChange);
    void attack(RPG* target);
    void useSkill(RPG* target);
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
