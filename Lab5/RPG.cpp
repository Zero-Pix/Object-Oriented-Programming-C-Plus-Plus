#include <string>
#include "RPG.h"

RPG::RPG() : name("npc"), strength(10), health(10), defense(10), type("warrior") {
    skills[0] = "slash";
    skills[1] = "parry";
}

RPG::RPG(std::string name, int health, int strength, int defense, std::string type)
    : name(name), strength(abs(strength)), health(abs(health)), defense(abs(defense)), type(type) {}

void RPG::updateHealth(int new_health) {
    health = new_health; 
}


bool RPG::isAlive() const {
    return health > 0;
}

std::string RPG::getName() const {
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}

void RPG::setSkills() {
    if (type == "Mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "Thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "Archer") {
        skills[0] = "parry";
        skills[1] = "Crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::printAction(std::string skill, RPG opponent) {
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

void RPG::attack(RPG *opponent) {
    int damage = strength - opponent->getDefense();
    if (damage < 0) damage = 0;
    int new_health = opponent->getHealth() - damage;
    if (new_health < 0) new_health = 0;
    opponent->updateHealth(new_health);
}

void RPG::useSkill(RPG *opponent){
    for (int i = 0; i < SKILL_SIZE; i++) {
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    printf("\nChoose a skill to use: Enter 0 or 1\n");
    int chosen_skill_index;
    std::cin >> chosen_skill_index;

    
    if (chosen_skill_index < 0 || chosen_skill_index >= SKILL_SIZE) {
        std::cout << "Invalid skill choice. Please try again.\n";
        return;
    }

    std::string chosen_skill = skills[chosen_skill_index];
    printAction(chosen_skill, *opponent);
    attack(opponent);
}
