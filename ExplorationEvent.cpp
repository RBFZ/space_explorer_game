#include "ExplorationEvent.h"

#include <iostream>
#include <cstdlib> // for rand() and srand()

using namespace std;

ExplorationEvent::ExplorationEvent() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));
}

DesertExplorationEvent::DesertExplorationEvent() : ExplorationEvent() {}

void DesertExplorationEvent::explore() {
    desertLanded = true;
    cout << "Your Spaceship lands on the dry and desolate planet...\n";
    cin.ignore();
    cout << endl;
    cout << "As your Crew decides where to journey to first, they come up with two options:" << endl;
    cin.ignore();
    cout << "1. Go east in search of an oasis for new plant life and water.\n";
    cout << "2. Go west to follow the wind in hopes of finding something more rare in this desolate land.\n";
    
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

        desertDragonChance = rand() % 2; // 0 or 1 for simplicity
        if (desertDragonChance == 1) {
            cout << "You managed to find your way back to the spaceship. The Crew is safe for now.\n";
            cin.ignore();
            // Implement logic for choosing the next planet or winning the game
            dragonDesert = false;
        } 
        else {
            cout << "As the Crew had managed to find your spaceship, they were about to depart.\nBut suddenly, even in this dangerous sandstorm, they spotted a large figure with wings...\n"; //dragon event
            cin.ignore();
            cout << "Your Crew stood there motionless inside the ship, unable to believe their eyes...\n";
            cin.ignore();
            cout << "It was a Desert Dragon!\n";
            cout << "(it was definitely a 'rare' find!)\n";
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

BlizzardExplorationEvent::BlizzardExplorationEvent() : ExplorationEvent() {}

void BlizzardExplorationEvent::explore() {
    iceLanded = true;
    cout << "Your Spaceship has landed on the icy land...\n";
    cin.ignore();
    cout << endl;
    cout << "After your Crew put on their special gear, they head out in search of something new...";
    cin.ignore();
    cout << "But suddenly a fierce blizzard strikes the land!\n";
    cin.ignore();
    cout << endl;
    cout << "This event had left youe Crew with two options:\n";
    cout << "1. Seek shelter and find a cave until the blizzard passes over.\n";
    cout << "2. Brave the blizzard and keep searching for life in the mountains.\n";
    
    cout << "Enter your choice: ";
    cin >> iceChoice;
    cout << endl;

    if (iceChoice == 1) {
        CaveChance = rand() % 2; // 0 or 1 for simplicity
        if (CaveChance == 1) {
            iceXpGain = true;
            cout << ". (+15 XP)\n";
            cout << "Despite the harsh environment, your Crew has found a cave! This will provide some shelter from the blizzard for the time being.\n";
            cin.ignore();
            cout << endl;
            
            IceShipChance = rand() % 2; // 0 or 1 for 50% chance
            if (IceShipChance == 1) {
                iceXpGain = true;
                cout << "As your crew settled down, they had decided to explore further down the large cave and found...\n";
                cin.ignore();
                cout << "An old spaceship!\n";
                cin.ignore();
                cout << "Judging by how cold the ship was, the crew decided to take a look inside.\n";
                cin.ignore();
                cout << "Sadly, there were no signs of life, But your crew had managed to salvage some old fuel.\n";
                cin.ignore();
                cout << endl;
                
            } 
            else {
                cout << "As your crew settled down, they had decided to explore further down the large cave...\n";
                cin.ignore();
                cout << "But had found nothing...\n";
                cin.ignore();
                cout << "Soon enough, the blizzard had passed over, and the Crew had returned to the ship and decided to depart from the Ice Planet.\n";
                cin.ignore();
                cout << endl;
            }
            
        } 
        else if (CaveChance == 0) {
            cout << "Unfortunately, after what felt like hours, your Crew did not find a cave to settle down in. One of your Crew members has suffered from frostbite on their feet.\n";
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
            IsurvivalChance = rand() % 2; // 0 or 1 for 50% chance
            if (IsurvivalChance == 1) {
                cout << "They survived! Your Crew member has recovered and is ready to continue the journey.\n";
                cout << "(+10 XP)";
                cin.ignore();
                cout << endl;
            } 
            else if (IsurvivalChance == 0){
                cout << "Sadly, despite your Crew's best efforts, the Crew member did not survive...\n";
                // Decrease crew capacity by 1
                cin.ignore();
            }
            
        }
    } 
}

VolcanoExplorationEvent::VolcanoExplorationEvent() : ExplorationEvent() {}

void VolcanoExplorationEvent::explore() {
    lavaLanded = true;
    cout << "A volcano erupts on the lava planet!\n";
    cout << "Options:\n";
    cout << "1. Evacuate to a safe location (chance of success)\n";
    cout << "2. Explore the area despite the eruption (risk of losing Crew members)\n";
    
    // Implement logic for player choice and consequences
}
