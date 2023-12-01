#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"



using namespace std;

#define DELAY_CONST 100000

GameMechs *myGameMechs;
Player *myPlayer;

//bool exitFlag;

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

    myGameMechs = new GameMechs();
    myPlayer = new Player(myGameMechs);

    //myGameMechs->setExitFalse();

    //myPos.setObjPos(6,11,'@');
}

void GetInput(void)
{
    if (MacUILib_hasChar() != 0)
    {
        myGameMechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    //MacUILib_printf("Object: <%d, %d> with %c\n", myPos.x, myPos.y, myPos.symbol);
    for (int y = 0; y < myGameMechs->getBoardSizeY(); y++) //draw the game board
    {
        for (int x = 0; x < myGameMechs->getBoardSizeX(); x++)
        {
            if (y == 0 || y == (myGameMechs->getBoardSizeY() - 1) || x == 0 || x == (myGameMechs->getBoardSizeX() - 1))
            {
                MacUILib_printf("%c", '#');
            }       
            else if (myPlayer->getPlayerXPos() == x && myPlayer->getPlayerYPos() == y)
            {
                MacUILib_printf("%c", myPlayer->getPlayerSymbol());
            }    
        }
        MacUILib_printf("\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen(); 
/*
    // game mechanics deallocation
    if (*myGameMechs != nullptr)
    {
        delete *myGameMechs;
    }
    // Set mainGameMechsRef to nullptr to avoid double deletion
    *myGameMechs = nullptr;*/

    delete &myGameMechs;


    MacUILib_uninit();
}
