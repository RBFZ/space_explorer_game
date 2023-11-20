#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H
#include <iostream>

using namespace std;


class RandomEvent {
public:
    RandomEvent();
    virtual void executeEvent() = 0;
    bool dragonOutcome; //true if win, false if deth
    bool dragonEscape; //true if escaped, false if deth
    int DragonChoice;
    
};

class DragonMonsterRandomEvent : public RandomEvent {
public:
    DragonMonsterRandomEvent();
    virtual void executeEvent() override;
    // Additional methods or properties specific to DragonMonsterRandomEvent
    bool getDragonOutcome(); //true if win, false if deth
    bool getDragonEscape(); //true if escaped, false if deth
    int getDragonChoice() {
        return DragonChoice;
    }
    
    
    
};

#endif // RANDOMEVENT_H
