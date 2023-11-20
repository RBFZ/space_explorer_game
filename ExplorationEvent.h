#ifndef EXPLORATIONEVENT_H
#define EXPLORATIONEVENT_H
#include <iostream>
#include <vector>
#include "Spaceship.h"
#include "Player.h"

using namespace std;

class ExplorationEvent {
public:
    ExplorationEvent();
    virtual void explore() = 0;
};

class DesertExplorationEvent : public ExplorationEvent {
private:
    bool desertLanded;
    bool dragonDesert;
    int desertChoice;
    bool desertXpGain;
    int DesertCrewChance;
    int OasisChance;
    int desertrandomChance;
    int DsurvivalChance;

public:
    DesertExplorationEvent();
    virtual void explore() override;
    bool getDragonDesert() {
        return dragonDesert;
    }
    int getDesertChoice() {
        return desertChoice;
    }
    bool getXpGain() {
        return desertXpGain;
    }
    bool getDesertLanded() {
        return desertLanded;
    }
    
    int getCrewChance() {
        return DesertCrewChance;
    }
    int getOasisChance() {
        return OasisChance;
    }
    int getDesertRandomChance() {
        return desertrandomChance;
    }
    int getDsurvivalChance() {
        return DsurvivalChance;
    }
    
};

class BlizzardExplorationEvent : public ExplorationEvent {
private:
    bool dragonIce;
    bool iceLanded;
    int blizzardChoice;
    bool blizzardXpGain;
    int IceCrewChance;
    //int CaveChance
public:
    BlizzardExplorationEvent();
    virtual void explore() override;
    bool getDragonIce() {
        return dragonIce;
    }
    int getBlizzardChoice() {
        return blizzardChoice;
    }
    bool getXpGain() {
        return blizzardXpGain;
    }
    int getCrewChance() {
        return IceCrewChance;
    }
    bool getIceLanded() {
        return iceLanded;
    }
    
};

class VolcanoEruptionExplorationEvent : public ExplorationEvent {
private:
    bool dragonLava;
    bool lavaLanded;
    int volcanoChoice;
    bool volcanoXpGain;
    int LavaCrewChance;
    //OasisChance
public:
    VolcanoEruptionExplorationEvent();
    virtual void explore() override;
    bool getDragonLava() {
        return dragonLava;
    }
    int getVolcanoChoice() {
        return volcanoChoice;
    }
    bool getXpGain() {
        return volcanoXpGain;
    }
    int getCrewChance() {
        return LavaCrewChance;
    }
    bool getLavaLanded() {
        return lavaLanded;
    }
    
    // Additional methods or properties specific to VolcanoEruptionExplorationEvent
};

#endif // EXPLORATIONEVENT_H
