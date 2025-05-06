#include "animatronic.h"

Animatronic::Animatronic(int ai)
{
    mAiLevel=ai;
}

int const Animatronic::getAiLevel()
{
    return mAiLevel;
}

std::string const Animatronic::getLocation()
{
    return mLocation;
}

void Animatronic::setAiLevel(int ai)
{
    mAiLevel=ai;
}

void Animatronic::setLocation(std::string location)
{
    mLocation=location; //String is a placeholder, open to ideas for determing location? keeping it as string is also fine
}

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

void Animatronic::moveRooms()
{
    //Decides which room to move to if there's a choice
    //Moves straight if no choice is available
}
