#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <ctime>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        
        int boardSizeX;
        int boardSizeY;

        objPos foodPos;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();

        void setExitTrue();
        void setLoseFlag();        
        void setInput(char this_input);
        void clearInput();
        void incrementScore();

        void generateFood(objPos blockOff); // you need to upgrade this somehow...
        // Need to accept the playerBody arrayList
        // Go through each array list element to make sure they are all blocked off from random food generation

        void getFoodPos(objPos &returnPos);
};

#endif