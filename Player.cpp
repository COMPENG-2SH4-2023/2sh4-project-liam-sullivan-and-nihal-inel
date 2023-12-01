#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = IDLE;

    // more actions to be included
    playerPos.setObjPos(5,5,'@');
}


Player::~Player()
{/*
    // delete any heap members here
    if (*mainGameMechsRef != nullptr)
    {
        delete *mainGameMechsRef;

        // Set mainGameMechsRef to nullptr to avoid double deletion
        *mainGameMechsRef = nullptr;
    }*/
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos = playerPos;
}
/*
int Player::getPlayerXPos()
{
    return playerPos.x;
}

int Player::getPlayerYPos()
{
    return playerPos.y;
}

char Player::getPlayerSymbol()
{
    return playerPos.symbol;
}*/

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    
    char input = mainGameMechsRef->getInput();

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case 27:  // exit
                //exitFlag = 1;
                mainGameMechsRef->setExitTrue();
                break;
            case 'W':
            case 'w':
                //move up
                if (myPrevDir != UP && myPrevDir != DOWN)
                {
                    myDir = UP;
                }
                break;
            case 'A':
            case 'a':
                //move left
                if (myPrevDir != RIGHT && myPrevDir != LEFT)
                {
                    myDir = LEFT;
                }
                break;
            case 'S':
            case 's':
                //move down
                if (myPrevDir != UP && myPrevDir != DOWN)
                {
                    myDir = DOWN;
                }
                break;
            case 'D':
            case 'd':
                //move right
                if (myPrevDir != RIGHT && myPrevDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;
            default:
                break;
        }
    }
    mainGameMechsRef->setInput(0);    
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (myDir) // update the player location by 1 unit in the direction stored in the program
    {
        case UP:
            playerPos.y--;

            if(playerPos.y <= 0)
            {
                playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;
        case DOWN:
            playerPos.y++;

            if (playerPos.y >= mainGameMechsRef->getBoardSizeY()-1)
            {
                playerPos.y = 1;
            }
            break;
        case LEFT:
            playerPos.x--;

            if(playerPos.x <= 0)
            {
                playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;
        case RIGHT:
            playerPos.x++;

            if (playerPos.x >= mainGameMechsRef->getBoardSizeX()-1)
            {
                playerPos.x = 1;
            }
            break;    
        default:
            break;
    }

    myPrevDir = myDir;
/*
    if (myDir != IDLE)
    {
        moveCount++; // increase move count unless the player is not moving
    }
*/
}

