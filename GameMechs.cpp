#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    
    boardSizeX = 30;
    boardSizeY = 15;

    exitFlag = false;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    exitFlag = false;
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