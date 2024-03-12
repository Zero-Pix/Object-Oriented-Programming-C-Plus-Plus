#include <iostream>
#include "RPG.h"

using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage"); 
    RPG p2 = RPG(); 

    cout << p1.getName() << " current stats" << endl;
    cout << "Health: " << p1.getHealth() << "\tStrength: " << p1.getStrength() << "\tDefense: " << p1.getDefense() << endl; 

    cout << p2.getName() << " current stats" << endl; 
    cout << "Health: " << p2.getHealth() << "\tStrength: " << p2.getStrength() << "\tDefense: " << p2.getDefense() << endl; 

    // Show an update for health
    p1.updateHealth(0);
    p2.updateHealth(0);
    
    cout << p1.getName() << "'s new health: " << p1.getHealth() << endl; 
    cout << p2.getName() << "'s new health: " << p2.getHealth() << endl; 

    // Show who still is alive
    cout << p1.getName() << " is alive: " << (p1.isAlive() ? "true" : "false") << endl; 
    cout << p2.getName() << " is alive: " << (p2.isAlive() ? "true" : "false") << endl; 

    return 0; 
}
