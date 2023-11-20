#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <iostream> // Include the standard input/output stream library for console operations

using namespace std; // Use the standard namespace to avoid prefixing std:: before standard library functions

class Spaceship { // Define the Spaceship class, this class represents a spaceship with fuel and crew capacity
private:
    int fuel_capacity; // Declare private integer for fuel capacity, this represents the maximum fuel the spaceship can hold
    int crew_capacity; // Declare private integer for crew capacity, this represents the maximum number of crew members the spaceship can hold

public:
    Spaceship();  // Default constructor for Spaceship class, this will create a spaceship with default values
    Spaceship(int fuel_capacity, int crew_capacity); // Constructor for Spaceship class with parameters for fuel and crew capacity, this will create a spaceship with specified fuel and crew capacity
    virtual ~Spaceship(); // Virtual destructor for Spaceship class, this will properly clean up the spaceship object when it is destroyed

    virtual void fueling(int amount); // Virtual function for fueling the spaceship, this will add the specified amount of fuel to the spaceship
    virtual void journey(); // Virtual function for embarking the spaceship, this will start the spaceship's journey
    virtual void home(); // Virtual function for disembarking the spaceship, this will end the spaceship's journey and return it to home

    /*void setFuelCapacity(int fuel_capacity);
    void setCrewCapacity(int crew_capacity);*/

    int getFuelCapacity() const;
    int getCrewCapacity() const;

    void increaseFuelCapacity(int increase) {
        fuel_capacity += increase;
    }

    void decreaseFuelCapacity(int decrease) {
        fuel_capacity -= decrease;
        if (fuel_capacity < 0) {
            fuel_capacity = 0;
        }
    }
    
    
    void decreaseCrewCapacity(int decrease);

    void increaseCrewCapacity(int increase);
    
};
#endif // SPACESHIP_H

