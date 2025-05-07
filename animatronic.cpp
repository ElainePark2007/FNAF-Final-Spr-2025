/**
 * @file animatronic.cpp
 * @author Matteo Coppola
 * @brief Animatronic class definition file
 * @date 2025-05-06
 */
#include "animatronic.h"

/**
 * @brief Construct a new Animatronic:: Animatronic object
 * 
 * @param ai Starting ai level
 */
Animatronic::Animatronic(int ai)
{
    mAiLevel=ai;
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
 * @return std::string const Location
 */
std::string const Animatronic::getLocation()
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
 * @brief Sets location of animatronic (used for testing)
 * 
 * @param location Location
 */
void Animatronic::setLocation(std::string location)
{
    mLocation=location; //String is a placeholder, open to ideas for determing location? keeping it as string is also fine
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
void Animatronic::movementOpportunity()
{
    int movement=rand()%20+1;
    std::cout<<movement<<std::endl;
    if(movement<=mAiLevel) {
        moveRooms();
    }
    //Gives animatronic the opportuntiy to move
    //Calls moveRooms() if true
}

/**
 * @brief Moves animatronic from room to room
 * 
 */
void Animatronic::moveRooms()
{
    //Decides which room to move to if there's a choice
    //Moves straight if no choice is available
}
