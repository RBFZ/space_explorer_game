#include "Spaceship.h"

Spaceship::Spaceship() : fuel_capacity(0), crew_capacity(0) {}

Spaceship::Spaceship(int fuel_capacity, int crew_capacity)
    : fuel_capacity(fuel_capacity), crew_capacity(crew_capacity) {}

Spaceship::~Spaceship() {}

void Spaceship::fueling(int amount) {
    if (amount > 0 && amount <= getFuelCapacity()) {
        fuel_capacity += amount;
    }
}

void Spaceship::journey() {
    // Implementation
}

void Spaceship::home() {
    // Implementation
}

/*void Spaceship::setFuelCapacity(int fuel_capacity) {
        this->fuel_capacity = fuel_capacity;
    }

void Spaceship::setCrewCapacity(int crew_capacity) {
        this->crew_capacity = crew_capacity;
    }*/

int Spaceship::getFuelCapacity() const {
        return fuel_capacity;
    }
int Spaceship::getCrewCapacity() const {
    return crew_capacity;
}


void Spaceship::decreaseCrewCapacity(int decrease) {
    if (crew_capacity > 0) {
        crew_capacity -= decrease;
    }
}

void Spaceship::increaseCrewCapacity(int increase) {
    crew_capacity += increase;
}

