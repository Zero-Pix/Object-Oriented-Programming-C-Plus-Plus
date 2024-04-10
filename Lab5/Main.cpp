#include <iostream>
#include "RPG.h"

using namespace std;


void displayStats(RPG p1, RPG p2){
    cout << p1.getName() << " current stats" << endl;
    cout << "Health: " << p1.getHealth() << "\tStrength: " << p1.getStrength() << "\tDefense: " << p1.getDefense() << endl; 

    cout << p2.getName() << " current stats" << endl; 
    cout << "Health: " << p2.getHealth() << "\tStrength: " << p2.getStrength() << "\tDefense: " << p2.getDefense() << endl; 
}

void displayEnd(RPG p1, RPG p2){
    cout << p1.getName() << " is alive: " << (p1.isAlive() ? "true" : "false") << endl; 
    cout << p2.getName() << " is alive: " << (p2.isAlive() ? "true" : "false") << endl; 
    
}

void gameLoop( RPG * p1, RPG*p2){
    while (p1->isAlive() && p2->isAlive()) {
        displayStats(*p1,*p2);
        (*p1).useSkill(p2);
     printf("\n--------------------------------\n");
     displayStats(*p2,*p1);
        (*p2).useSkill(p1);
     printf("\n--------------------------------\n");
    }
}



int main(){
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);

    displayEnd(p1, p2);
    if (p1.isAlive()) {
        cout << p1.getName() << " won! Congrats! " << endl;
    } else {
        cout << p2.getName() << " won! Congrats! " << endl;
    }

    return 0;
}