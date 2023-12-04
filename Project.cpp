#include <iostream>
#include <ctime>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *myGameMechs;
Player *myPlayer;

//objPos playerPos;
//objPos foodPos; // may need to move this inside the drawscreen function


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    Initialize();

    while(myGameMechs->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    srand(static_cast<unsigned int>(time(nullptr)));

    myGameMechs = new GameMechs(26,13);
    myPlayer = new Player(myGameMechs);

    // think about when to generate new food..
    // think about whether u want to set up a debug key to call the food generation routine for verification
    // remember, generateFood() requires player reference. you will need to provide it AFTER object is instantiated
/*
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); // commented out for now to modify later using objPosArrayList instead of objPos
    myGameMechs->generateFood(tempPos);
*/

    // temporarily keep this as a fix for the above commented out code:
    objPos tempPos(-1, -1, 'o');
    myGameMechs->generateFood(tempPos); // once generateFood method is upgraded to accept objPosArrayList, we wont need tempPos, above line will be deleted
}

void GetInput(void)
{
    myGameMechs->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
/*
    myGameMechs->getFoodPos(foodPos);

    if (playerPos.isPosEqual(&foodPos))
    {
        myGameMechs->incrementScore();
        myGameMechs->generateFood(playerPos);
        myGameMechs->getFoodPos(foodPos);

    }
*/
    myGameMechs->clearInput(); // prevents repeatedly processing the input
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    myGameMechs->getFoodPos(tempFoodPos);

    for (int y = 0; y < myGameMechs->getBoardSizeY(); y++) //draw the game board
    {
        for (int x = 0; x < myGameMechs->getBoardSizeX(); x++)
        {
            drawn = false;

            // iterata thru every single element in the list
            for (int i = 0; i < playerBody->getSize(); i++)
            {
                playerBody->getElement(tempBody, i);

                if (tempBody.x == x && tempBody.y == y)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if (drawn) continue;
            // if playerBody was drawn, don't draw anything below.

            if (y == 0 || y == (myGameMechs->getBoardSizeY() - 1) || x == 0 || x == (myGameMechs->getBoardSizeX() - 1)) // draw border
            {
                MacUILib_printf("%c", '#');
            }
            else if (x == tempFoodPos.x && y == tempFoodPos.y) // draw food
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d\n", myGameMechs->getScore());

    MacUILib_printf("Food Pos: <%d, %d>\n", tempFoodPos.x,tempFoodPos.y);
/*
    MacUILib_printf("Board Size: %dx%d, Player Pos: <%d, %d> + %c\n", 
                    myGameMechs->getBoardSizeX(),
                    myGameMechs->getBoardSizeY(),
                    tempPos.x, tempPos.y, tempPos.symbol);
*/
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_uninit();

    // remove heap instances
    delete myGameMechs;
    delete myPlayer;
}