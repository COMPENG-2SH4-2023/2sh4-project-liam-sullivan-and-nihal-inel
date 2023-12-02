#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList()
{
    // initialize sizeArray and sizeList
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0; // not sure about this

    // allocate an array in the heap with the size specified by sizeArray
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    // deallocate all heap data members
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (sizeList != sizeArray)
    {
        for (int i = sizeList; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }
        aList[0].setObjPos(thisPos);
        sizeList++;
    }    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (sizeList != sizeArray)
    {
        aList[sizeList].setObjPos(thisPos);
        sizeList++;
    }
}

void objPosArrayList::removeHead()
{
    if (sizeList != 0)
    {
        for (int i = 0; i < sizeList - 1; i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }
        sizeList--;
    }
}

void objPosArrayList::removeTail()
{
    if (sizeList != 0)
    {
        sizeList--; // not sure if this is correct or not
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}