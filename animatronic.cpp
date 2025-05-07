/**
 * @file animatronic.cpp
 * @author Matteo Coppola
 * @brief Animatronic class definition file
 * @date 2025-05-06
 */
#include "animatronic.h"
#include "room.h"

Animatronic::Animatronic(int ai, Room &location)
{
    mAiLevel=ai;
    mLocation=&location;
    mLocation->switchToAnimatronicState();
}

/**
 * @brief Returns current ai level of animatronic
 * 
 * @return int const Ai level
 */
int const Animatronic::getAiLevel()
{
    return mAiLevel;
}

Room* const Animatronic::getLocation()
{
    return mLocation;
}

/**
 * @brief Sets ai level of animatronic
 * 
 * @param ai Ai level
 */
void Animatronic::setAiLevel(int ai)
{
    mAiLevel=ai;
}

void Animatronic::setLocation(Room location)
{
    mLocation=&location; //String is a placeholder, open to ideas for determing location? keeping it as string is also fine
}

/**
 * @brief Increments ai level
 * 
 */
void Animatronic::aiIncrease()
{
    mAiLevel++; //Increases depending on time of night
}

/**
 * @brief Decides if animatronic should move based on random numbers
 * 
 */
bool Animatronic::movementOpportunity(bool &jumpscare)
{
    int movement=rand()%20+1;
    if(movement<=mAiLevel) {
        return moveRooms(jumpscare);
    }
    return false;
    //Gives animatronic the opportuntiy to move
    //Calls moveRooms() if true
}

bool Animatronic::moveRooms(bool &jumpscare)
{
    if(mLocation->getNextRoom()==nullptr) {
        return true;
    } else if(!(mLocation->getNextRoom()->getAnimatronicState())) {
        mLocation->switchAnimatronicState();
        mLocation=mLocation->getNextRoom();
        mLocation->switchAnimatronicState();
        return false;
    }
    return false;
}
