#include <iostream>
#include "RPG.h"

RPG::RPG() : name("npc"), strength(10), health(10), defense(10), type("warrior") {
    skills[0] = "slash";
    skills[1] = "parry";
}

RPG::RPG(std::string name, int health, int strength, int defense, std::string type)
    : name(name), strength(strength), health(health), defense(defense), type(type) {}

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

void RPG::printAction(string skill, RPG opponent) {
     Printf("%s used %s on %s/n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}