#include "GameMechs.h"
#include "MacUILib.h"

#include <cstdlib>
#include <ctime>

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;

    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1,-1,'o'); // initialize foodPos outside of the game board
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;

    boardSizeX = boardX;
    boardSizeY = boardY;

    foodPos.setObjPos(-1,-1,'o'); // initialize foodPos outside of the game board
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // may not be needed
}

// Getters
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar() != 0)
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

// Setters
void GameMechs::setExitTrue()
{
    exitFlag = true;
}
/*/
void GameMechs::setExitFalse()
{
    exitFlag = false;
}
*/
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0; // ?? not sure about this
}

void GameMechs::incrementScore() // Specialized setter for the score field. 
{
    score++;
    // Assumption is that the score can only be incremented 1 at a time for every food collected.
    // You may consider changing this method to allow the score to be increased by numbers other than 1.
}

void GameMechs::generateFood(objPos blockOff)
{
    // The random food generation algorithm should be placed here. (copy from PPA3)
    // blockOff should contain the player position, on which the new food should NOT be generated

    // PSEUDOCODE:
    // generate random x and y coordinates, and make sure they are NOT boarder of blockOff pos
    // check x and y against 0 and boardsizex/y
    // remember! in objPos class you have an isPosEqual() method. 
                //Use this instead of comparing element by element for your convenience
    
    int candidateX;
    int candidateY;
    bool isValid = true;

    candidateX = rand() % boardSizeX;
    candidateY = rand() % boardSizeY;

    objPos candidate(candidateX, candidateY, 'o');

    //if (blockOff.x == candidateX && blockOff.y == candidateY)
    if (blockOff.isPosEqual(&candidate))
    {
        isValid = false;
    }
    else if (candidateY == 0 || candidateY == boardSizeY - 1 || candidateX == 0 || candidateX == boardSizeX - 1)
    {
        isValid = false;
    }

    if (isValid == true)
    {
        // foodPos.setObjPos(candidateX, candidateY, 'o');
        foodPos.setObjPos(candidate);
    }
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}