#include "Planets.h"
#include <iostream>

Planet::Planet()
    : name(""), description(""), fuel_required(0), hostility_level(0), explorationEvent(nullptr) {}

Planet::Planet(std::string name, std::string description, int fuel_required, int hostility_level, ExplorationEvent* explorationEvent)
    : name(name), description(description), fuel_required(fuel_required), hostility_level(hostility_level), explorationEvent(explorationEvent) {}

Planet Planet::createDesertPlanet() {
    return Planet("Desert Planet", "A hot and arid desert world. Semi-hazardous environment due to occasional sandstorms", 30, 2, new DesertExplorationEvent());
}

Planet Planet::createIcePlanet() {
    return Planet("Ice Planet", "A frozen ice-covered planet. Very mountainous regions that are covered in snow due to common blizzards and deathly avalanches", 40, 3, new BlizzardExplorationEvent());
}

Planet Planet::createLavaPlanet() {
    return Planet("Lava Planet", "A land of rivers full of lava circulating in all directions. This extremely dangerous planet is layered with active volcanoes and blazing magma geysers.", 35, 4, new VolcanoEruptionExplorationEvent());
}

void Planet::displayInfo() {
    cout << "Planet: " << name << "\nDescription: " << description
              << "\nFuel Required: " << fuel_required << "\nHostility Level: " << hostility_level << "\n\n";
}

void Planet::explorePlanet() {
    cout << "You have chosen the " << name << "...\n";
    cout << endl;
    cout << "Brief Summary Report on Planet of Interest (POI):\n";
    cout << endl;
    
    // Display planet information
    displayInfo();

    // Execute the exploration event
    if (explorationEvent != nullptr) {
        explorationEvent->explore();
    }
    
    
}

bool Planet::isVisited() const {
    return visited;
}

int Planet::getFuelRequired() const { return fuel_required; }
