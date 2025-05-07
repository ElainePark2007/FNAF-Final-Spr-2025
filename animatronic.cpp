/**
 * @file animatronic.cpp
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Animatronic class definition file
 * @date 2025-05-06
 */
#include "animatronic.h"
#include "room.h"

/**
 * @brief Construct a new Animatronic:: Animatronic object
 * 
 * @param ai Default ai level
 * @param location Default location
 */
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

/**
 * @brief Returns location of animatronic
 * 
 * @return Room* const Pointer to room object
 */
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

/**
 * @brief Sets location of animatronic
 * 
 * @param location Location to move to
 */
void Animatronic::setLocation(Room &location)
{
    mLocation->switchAnimatronicState();
    mLocation=&location;
    mLocation->switchAnimatronicState();
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

/**
 * @brief Moves animatronic to next room
 * 
 * @param jumpscare True if animatronic is ready to jumpscare
 * @return true animatronic will scare
 * @return false animatronic won't scare
 */
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
