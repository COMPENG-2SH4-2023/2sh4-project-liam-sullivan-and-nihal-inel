#include "Player.h"
#include "objPos.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = IDLE;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                      mainGameMechsRef->getBoardSizeY()/2, '*');
    //objPos tempPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@'); // can also be written like this

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    // for debugging purpose - insert another 4 segments
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);

    // once food collision algorithm is implemented in food generation, do not leave the above 4 lines of code in there
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
//objPos Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return  playerPosList;
}

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
    //mainGameMechsRef->setInput(0);    
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    switch (myDir) // update the player location by 1 unit in the direction stored in the program
    {
        case UP:
            currentHead.y--;

            if(currentHead.y <= 0)
            {
                currentHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;
        case DOWN:
            currentHead.y++;

            if (currentHead.y >= mainGameMechsRef->getBoardSizeY()-1)
            {
                currentHead.y = 1;
            }
            break;
        case LEFT:
            currentHead.x--;

            if(currentHead.x <= 0)
            {
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;
        case RIGHT:
            currentHead.x++;

            if (currentHead.x >= mainGameMechsRef->getBoardSizeX()-1)
            {
                currentHead.x = 1;
            }
            break;   
        //case IDLE; 
        default:
            break;
    }

    // new current head should be inserted to the head of the list
    playerPosList->insertHead(currentHead);

    if (checkFoodConsumption() != true)
    {
        playerPosList->removeTail();
    }
    else
    {
        objPos head;
        playerPosList->getHeadElement(head);
        mainGameMechsRef->generateFood(head);
    }

    myPrevDir = myDir;
}

bool Player::checkFoodConsumption()
{
    objPos foodPos;
    mainGameMechsRef->getFoodPos(foodPos);

    objPos headPos;
    playerPosList->getHeadElement(headPos);

    if (foodPos.x == headPos.x && foodPos.y == headPos.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Player::increasePlayerLength()
{
    
}
