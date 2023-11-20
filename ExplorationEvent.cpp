#include "ExplorationEvent.h"

#include <iostream>
#include <cstdlib> // for rand() and srand()

using namespace std;

ExplorationEvent::ExplorationEvent() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));
}

DesertExplorationEvent::DesertExplorationEvent() : ExplorationEvent() {
    // Additional initialization for DesertExplorationEvent
}

void DesertExplorationEvent::explore() {
    desertLanded = true;
    cout << "Your Spaceship lands on the dry and desolate planet...\n";
    cin.ignore();
    cout << endl;
    cout << "As your Crew decides where to journey to first, they come up with two options:" << endl;
    cin.ignore();
    cout << "1. Search for an oasis (chance of XP Gain, or risk of dehydration)\n";
    cout << "2. Keep walking in hopes of finding something(risk of losing Crew members)\n";
    
    cout << "Enter your choice: ";
    cin >> desertChoice;
    cout << endl;
    // Implement logic for player choice and consequences
    if (desertChoice == 1) {
        OasisChance = rand() % 2; // 0 or 1 for simplicity
        if (OasisChance == 1) {
            desertXpGain = true;
            cout << "Congratulations! You found an oasis and new plants have been discovered!. (+15 XP)\n";
            //xp gain
            cin.ignore();

            DesertCrewChance = rand() % 2; // 0 or 1 for 50% chance
            if (DesertCrewChance == 1) {
                cout << "Your Crew were studying this new area and have discovered a lost Crew member in the oasis!\n";
                cin.ignore();
                cout << "You have stocked up on supplies (and a new Crew member) and are ready depart from the Desert planet.\n";
                //crew member +1
                cin.ignore();
            } 
            else {
                cout << "Your Crew have finished studying the area.\n";
                cin.ignore();
                cout << "You have stocked up on supplies and are ready to depart from the Desert planet.\n";
                cin.ignore();
            }
            
        } 
        else if (OasisChance == 0) {
            cout << "Unfortunately, after many hours of searching, your Crew did not find an oasis. One of your Crew members has fainted due to dehydration.\n";
            // Decrease crew capacity by 1
            cin.ignore();
            cout << endl;
            cout << "Because of this, the rest of your Crew decided to head back to the ship and quickly provide aid.\n";
            cin.ignore();
            cout << "As your Crew arrived back at the ship, they discovered that the Crew member's state was severe...";
            cin.ignore();
            cout << "The Crew treated them to the best of their abilities, and...";
            cin.ignore();
            cout << endl;
            DsurvivalChance = rand() % 2; // 0 or 1 for 50% chance
            if (DsurvivalChance == 1) {
                cout << "They survived! Your Crew member has recovered and is ready to continue the journey.\n";
                cout << "(+10 XP)";
                cin.ignore();
                cout << endl;
            } 
            else if (DsurvivalChance == 0){
                cout << "Sadly, despite your Crew's best efforts, the Crew member did not survive...\n";
                // Decrease crew capacity by 1
                cin.ignore();
            }
            
        }
    } 
    else if (desertChoice == 2) {
        // Implement logic for walking and finding shelter (e.g., decrease crew members by 1)
        cout << "You decided to keep exploring. Some Crew members have become dehydrated as a very dangerous sandstorm emerges.\n";
        cin.ignore();
        cout << "Because of this deadly sandstorm, your Crew has to turn back and locate the ship.\n";
        cin.ignore();

        desertrandomChance = rand() % 2; // 0 or 1 for simplicity
        if (desertrandomChance == 1) {
            cout << "You managed to find your way back to the spaceship. The Crew is safe for now.\n";
            cin.ignore();
            // Implement logic for choosing the next planet or winning the game
            dragonDesert = false;
        } 
        else {
            cout << "As the Crew had managed to find your spaceship, they were about to depart.\nBut suddenly, even in this dangerous sandstorm, they spotted a large figure with wings...\n"; //dragon event
            cin.ignore();
            cout << "Your Crew stood there motionless inside the ship, unable to beleive their eyes...\n";
            cin.ignore();
            cout << "It was a Desert Dragon!\n";
            cin.ignore();
            dragonDesert = true;
            cout << endl;
            cout << "YOUR CREW NEEDS GUIDANCE TO SURVIVE!\n";
            cout << endl;
            cout << "Pick an option, and choose carefully, your Crew's lives depend on it!\n";
        } 
    }
    else {
        cout << "Invalid input, restarting dialogue..." << "\n";
        explore();
    }
}

BlizzardExplorationEvent::BlizzardExplorationEvent() : ExplorationEvent() {
    // Additional initialization for BlizzardExplorationEvent
}

void BlizzardExplorationEvent::explore() {
    iceLanded = true;
    cout << "A fierce blizzard begins!\n";
    cout << "Options:\n";
    cout << "1. Seek shelter (chance of success)\n";
    cout << "2. Brave the blizzard (risk of losing Crew members)\n";
    
    // Implement logic for player choice and consequences
}

VolcanoEruptionExplorationEvent::VolcanoEruptionExplorationEvent() : ExplorationEvent() {
    // Additional initialization for VolcanoEruptionExplorationEvent
}

void VolcanoEruptionExplorationEvent::explore() {
    lavaLanded = true;
    cout << "A volcano erupts on the lava planet!\n";
    cout << "Options:\n";
    cout << "1. Evacuate to a safe location (chance of success)\n";
    cout << "2. Explore the area despite the eruption (risk of losing Crew members)\n";
    
    // Implement logic for player choice and consequences
}
