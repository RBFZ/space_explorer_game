#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int xp;

public:
    Player() : xp(0) {}

    void gainXP(int amount) {
        xp += amount;
    }

    void loseXP(int amount) {
        xp -= amount;
        if (xp < 0) xp = 0;
    }

    int getXP() const {
        return xp;
    }
    void setXP(int amount) {
        xp = amount;
        if (xp < 0) xp = 0;
    }
    
};

#endif