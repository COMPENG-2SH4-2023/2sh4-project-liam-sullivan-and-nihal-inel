#include <iostream>
#include <ctime>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *myGameMechs;
Player *myPlayer;

objPos playerPos;
objPos foodPos;


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
    
    myPlayer->getPlayerPos(playerPos);
    myGameMechs->generateFood(playerPos);
}

void GetInput(void)
{
    myGameMechs->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGameMechs->getFoodPos(foodPos);

    if (playerPos.isPosEqual(&foodPos))
    {
        myGameMechs->incrementScore();
        myGameMechs->generateFood(playerPos);
        myGameMechs->getFoodPos(foodPos);

    }

    myGameMechs->clearInput(); // prevents repeatedly processing the input
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); // get the player pos

    for (int y = 0; y < myGameMechs->getBoardSizeY(); y++) //draw the game board
    {
        for (int x = 0; x < myGameMechs->getBoardSizeX(); x++)
        {
            if (tempPos.x == x && tempPos.y == y)
            {
                printf("%c", tempPos.symbol);
            }
            else if (y == 0 || y == (myGameMechs->getBoardSizeY() - 1) || x == 0 || x == (myGameMechs->getBoardSizeX() - 1))
            {
                printf("%c", '#');
            }
            else if (x == foodPos.x && y == foodPos.y)
            {
                printf("%c", foodPos.symbol);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    MacUILib_printf("Score: %d, Player Pos: <%d, %d>\n",
                    myGameMechs->getScore(),
                    tempPos.x, tempPos.y);

    MacUILib_printf("Food Pos: <%d, %d>\n", foodPos.x,foodPos.y);
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