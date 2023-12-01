#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, IDLE};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
/*
        int getPlayerXPos();
        int getPlayerYPos();
        char getPlayerSymbol();*/

        void updatePlayerDir();
        void movePlayer();

    private:
        objPos playerPos;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        enum Dir myPrevDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif