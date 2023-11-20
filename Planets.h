// Include the ExplorationEvent class
#include "ExplorationEvent.h"

#include <iostream>
#include <string>
using namespace std;

class Planet {
private:
    bool visited;
    int fuelCapacity;
    string name;
    string description;
    int fuel_required;
    int hostility_level;
    ExplorationEvent* explorationEvent;

public:
    Planet();
    Planet(string name, string description, int fuel_required, int hostility_level, ExplorationEvent* explorationEvent);
    static Planet createDesertPlanet();
    static Planet createIcePlanet();
    static Planet createLavaPlanet();
    int getFuelRequired() const;
    int getFuelCapacity() const { return fuelCapacity; }
    string getName() const { return name; }
    ExplorationEvent* getExplorationEvent() const { return explorationEvent; }

    void displayInfo();
    void explorePlanet();
    bool isVisited() const;
};