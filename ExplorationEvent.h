#ifndef EXPLORATIONEVENT_H
#define EXPLORATIONEVENT_H
#include <iostream>
#include <vector>
#include "Spaceship.h"
#include "Player.h"
#include "DragonEvent.h"

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
    int desertDragonChance;
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
    int getdesertDragonChance() {
        return desertDragonChance;
    }
    int getDsurvivalChance() {
        return DsurvivalChance;
    }
    
};

class BlizzardExplorationEvent : public ExplorationEvent {
private:
    bool iceLanded;
    bool dragonIce;
    int iceChoice;
    bool iceXpGain;
    int IceShipChance;
    int CaveChance;
    int iceDragonChance;
    int IsurvivalChance;
public:
    BlizzardExplorationEvent();
    virtual void explore() override;
    bool getDragonIce() {
        return dragonIce;
    }
    int getIceChoice() {
        return iceChoice;
    }
    bool getXpGain() {
        return iceXpGain;
    }
    int getShipChance() {
        return IceShipChance;
    }
    bool getIceLanded() {
        return iceLanded;
    }
    int getCaveChance() {
        return CaveChance;
    }
    
};

class VolcanoExplorationEvent : public ExplorationEvent {
private:
    bool lavaLanded;
    bool dragonLava;
    int lavaChoice;
    bool lavaXpGain;
    int LavaGoldChance;
    int HotSpringChance;
    int lavaDragonChance;
    int LsurvivalChance;
public:
    VolcanoExplorationEvent();
    virtual void explore() override;
    bool getDragonLava() {
        return dragonLava;
    }
    int getLavaChoice() {
        return lavaChoice;
    }
    bool getLavaXpGain() {
        return lavaXpGain;
    }
    int getLavaGoldChance() {
        return LavaGoldChance;
    }
    int getHotSpringChance() {
        return HotSpringChance;
    }
    int getLavaDragonChance() {
        return lavaDragonChance;
    }
    int getLsurvivalChance() {
        return LsurvivalChance;
    }
    bool getLavaLanded() {
        return lavaLanded;
    }
    
    // Additional methods or properties specific to VolcanoEruptionExplorationEvent
};

#endif // EXPLORATIONEVENT_H
