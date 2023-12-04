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

        //void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();

        void movePlayer(); // modify this
        // Need more actions in here:
        // - after inserting the head but before removing the tail
        // - check if new head position collides with food
        // - if yes, increment the score in game mechanics, generate new food, and do not remove tail, 
        // - if no, remove tail and move on

        //Lastly, add self collision check
        // - if self collided, set loose flag and exit flag to true (through game mechanics)
        // this will break the program loop and end the game
        //
        // if ending, you need to differentiate the end game state
        // LOST - display LOST message
        // otherwise, display ENDGAME message only

        bool checkFoodConsumption();
        void increasePlayerLength();

    private:
        objPosArrayList *playerPosList;
        enum Dir myDir;
        enum Dir myPrevDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif