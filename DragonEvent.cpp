#include "DragonEvent.h"
#include "Spaceship.h"
#include <iostream>

using namespace std;

RandomEvent::RandomEvent() {}

DragonMonsterRandomEvent::DragonMonsterRandomEvent() : RandomEvent() {
    // Additional initialization for DragonMonsterRandomEvent
}

void DragonMonsterRandomEvent::executeEvent() {
    cout << endl;
    cout << "1. Fight the Dragon with Advanced AI Spaceship Weaponry (chance of reward/XP, or risk of annihilation...)\n";
    cout << "2. GET OUTTA THERE! (use fuel)\n";
    
    cin >> DragonChoice;

    if (DragonChoice == 1) {
        // Player chose to fight the dragon
        int successChance = rand() % 2; // 0 or 1 for simplicity
        if (successChance == 1) {
            this->dragonOutcome = true;
            cout << "Congratulations! As the fight prolonged, you prevailed in this battle against the dragon! (+20 XP)\n";
            // Here, you can instantiate and assign a Jetspaceship to the player's spaceship
            cout << "As a reward for your bravery, the game admin has upgraded your spaceship to a Jet Spaceship!\n";
            cout << "You now have 30 more fuel capacity to zoom around even faster!\n";
        } 
        else {
            cout << "You failed to defeat the dragon. The spaceship is destroyed, and you perish.\n";
            // Implement game over logic here
            this->dragonOutcome = false;
            //end game
        }
    } 
    else if (DragonChoice == 2) {
        // Player chose to run away
        // Implement logic for running away (e.g., decrease fuel by 5)
        this->dragonEscape = true;
        cout << "Your crew escaped to orbit from the dragon, but lost 15 units of fuel in the process.\n";
        //-15 fuel
    } 
    else {
        cout << "Invalid choice. The dragon's mouth is fuming with smoke, hurry and make a decision!\n";
        executeEvent();
    }
}
bool DragonMonsterRandomEvent::getDragonOutcome() {
    return this->dragonOutcome;
}

bool DragonMonsterRandomEvent::getDragonEscape() {
    return this->dragonEscape;
}
