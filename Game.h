#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <vector>
#include <iostream>
#include "Planets.h"

class Game {
private:
    Spaceship* playerSpaceship;
    vector<Planet*> planets;
    int currentPlanetIndex;  // Track the current planet index
    Player* player;  // Pointer to the player to track XP


public:
    Game();
    ~Game();

    void startGame();
    void endGame();
    void saveGame();
    void loadGame();
    void addPlanet(Planet* planet);
    void exploreCurrentPlanet();
};

#endif // GAME_H
