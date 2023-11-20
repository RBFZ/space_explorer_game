#include "Game.h"

Game::Game() : currentPlanetIndex(0) {
    // Initialize playerSpaceship and other necessary setup
    playerSpaceship = new Spaceship(130, 3);
    player = new Player();
    
}

Game::~Game() {
    // Deallocate memory for planets and exploration events
    for (Planet* planet : planets) {
        delete planet;
    }
    planets.clear();

    // Deallocate memory for playerSpaceship
    delete playerSpaceship;
}

void Game::addPlanet(Planet* planet) {
    planets.push_back(planet);
}

void Game::startGame() {
    // Initialize the game, set up planets dynamically
    Planet* desertPlanet = new Planet("Desert Planet", "A hot and arid desert world.", 30, 2, new DesertExplorationEvent());
    Planet* icePlanet = new Planet("Ice Planet", "A frozen ice-covered planet.", 40, 3, new BlizzardExplorationEvent());
    Planet* lavaPlanet = new Planet("Lava Planet", "A planet with rivers of molten lava.", 35, 4, new VolcanoEruptionExplorationEvent());

    // Add planets to the game
    addPlanet(desertPlanet);
    addPlanet(icePlanet);
    addPlanet(lavaPlanet);

    // Output selection menu for planets or quit option
    cout << "\nWelcome to Space Odyssey!\n";
    cout << "In this game, you will explore different planets, each with their own unique challenges.\n";
    cout << "You can gain experience points (XP) by successfully overcoming these challenges.\n";
    cout << "You can also gain or lose crew members based on your decisions.\n";
    cout << "Your spaceship can be upgraded through valiant efforts!\n";
    cout << "But beware, there are many dangers lurking in the cosmos...\n";
    cout << endl;
    cout << "Good luck, and may the stars guide your journey!\n";
    
    cout << "Important Hint: Hit 'Enter' on your keyboard to continue when game dialogue pauses." << endl;
    cin.ignore();
    
    unsigned int choice;
    do {
        cout << "\nPlease select a planet to explore or quit the game:\n";
        for (int i = 0; i < planets.size(); i++) {
            cout << i + 1 << ". " << planets[i]->getName() << "\n";
        }
        cout << planets.size() + 1 << ". Refuel with XP\n";
        cout << planets.size() + 2 << ". Quit game\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice > 0 && choice <= planets.size()) {
            currentPlanetIndex = choice - 1;
            exploreCurrentPlanet();
        } 
        else if (choice == planets.size() + 1) {
            int xp = player->getXP();
            if (xp > 0) {
                playerSpaceship->increaseFuelCapacity(xp);
                player->setXP(0);
                cout << "You have used your XP to refuel. Your fuel capacity is now: " << playerSpaceship->getFuelCapacity() << "\n";
            } else {
                cout << "You have no XP points to refuel.\n";
            }
            
        }
        else if (choice == planets.size() + 2) {
            endGame();
            return;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != planets.size() + 2);
}
    

void Game::exploreCurrentPlanet() {
    // Ensure there is at least one planet
    if (planets.empty()) {
        cout << "No planets available to explore.\n";
        return;
    }

    // Decrease fuel capacity when moving to a new planet
    int fuelRequired = planets[currentPlanetIndex]->getFuelRequired();
    if (playerSpaceship->getFuelCapacity() < fuelRequired) {
        cout << "Unfortunately you do not enough fuel to travel to the next planet. Game over!\n";
        endGame();
        return;
    }
    
    // Explore the current planet (the last planet added)
    planets[currentPlanetIndex]->explorePlanet();

    // Check if the planet being explored is the desert planet
    if (planets[currentPlanetIndex]->getName() == "Desert Planet") {
        DesertExplorationEvent* desertEvent = dynamic_cast<DesertExplorationEvent*>(planets[currentPlanetIndex]->getExplorationEvent());
        playerSpaceship->decreaseFuelCapacity(fuelRequired);
        if (desertEvent != nullptr) {
            if (desertEvent->getDesertChoice() == 1) {
                if (desertEvent->getOasisChance() == 1) {
                    if (desertEvent->getXpGain()) {
                        this->player->gainXP(15); //gain xp for finding oasis
                    }
                    if (desertEvent->getCrewChance() == 1) { //found crew member in oasis
                    playerSpaceship->increaseCrewCapacity(1);
                    }
                }
                else if (desertEvent->getOasisChance() == 0) {
                    if (desertEvent->getDsurvivalChance() == 1) {
                        this->player->gainXP(10);
                    }
                    else if (desertEvent->getDsurvivalChance() == 0) {
                        playerSpaceship->decreaseCrewCapacity(1); // decrease crew member due to dehydration
                    }
                }
                cout << "Current Units of Fuel: " << playerSpaceship->getFuelCapacity() << "\n";
                cout << "Current Crew Number: " << playerSpaceship->getCrewCapacity() << "\n";
                cout << "Current XP: " << player->getXP() << "\n";
            }
            if (desertEvent->getDesertChoice() == 2) {
                if (desertEvent->getDragonDesert()) {
                    DragonMonsterRandomEvent dragonEvent;
                    dragonEvent.executeEvent();
                    if (dragonEvent.getDragonChoice() == 1){
                        if (dragonEvent.getDragonOutcome()) {
                            player->gainXP(20);
                            playerSpaceship->increaseFuelCapacity(30);
                        }
                        else if (!dragonEvent.getDragonOutcome()) {
                            endGame();
                            return;
                        }
                    }
                    else if(dragonEvent.getDragonChoice() == 2) {
                        if (dragonEvent.getDragonEscape()) {
                            playerSpaceship->decreaseFuelCapacity(15);
                        }
                    }
                }
                cout << "Current fuel: " << playerSpaceship->getFuelCapacity() << "\n";
                cout << "Current crew number: " << playerSpaceship->getCrewCapacity() << "\n";
                cout << "Current XP: " << player->getXP() << "\n";
            }
        }
    }
    // Check if the planet being explored is an ice planet //hostile level 3, so more change of loss, bigger reward
    else if (planets[currentPlanetIndex]->getName() == "Ice Planet") { //out of 2/3 for random chance
        
    }
    // Check if the planet being explored is a lava planet // hostile level 4, even more change of loss, bigger reward
    else if (planets[currentPlanetIndex]->getName() == "Lava Planet") { //3/4 for random chance
        
    }

    // Move to the next planet if there are more planets
    //if (function for planet exited = true)
    if (currentPlanetIndex < planets.size() - 1) {
        cout << "Moving to the next planet...\n";
    } else {
        cout << "Congratulations! You have explored all planets.\n";
        endGame();
    }
}
void Game::endGame() {
    // Destroy everything
    cout << "Game over. Thank you for playing!\n";
    for (Planet* planet : planets) {
        delete planet;
    }
    planets.clear();

    // Deallocate memory for playerSpaceship
    if (playerSpaceship != nullptr) {
        delete playerSpaceship;
        playerSpaceship = nullptr;
    }

    // Reset current planet index
    currentPlanetIndex = 0;

    // Reset player
    if (player != nullptr) {
        delete player;
        player = nullptr;
    }
}

void Game::saveGame() {
    // Save the game state to a file
}

void Game::loadGame() {
    // Load the game state from a file
}

