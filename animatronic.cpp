#include "animatronic.h"

Animatronic::Animatronic(int ai)
{
    mAiLevel=ai;
}

int Animatronic::getAiLevel()
{
    return mAiLevel;
}

std::string Animatronic::getLocation()
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

void Animatronic::movementOpportunity(int ai)
{
    //Gives animatronic the opportuntiy to move
    //Calls moveRooms() if true
}

void Animatronic::moveRooms()
{
    //Decides which room to move to if there's a choice
    //Moves straight if no choice is available
}

void Animatronic::timer()
{
    auto start = steady_clock::now();
    auto one_second = 1s;
    for (int i = 0; i < mWait; i++)
    {
        std::this_thread::sleep_for(one_second);
    }
}

void Animatronic::timerLength(int wait)
{
    mWait = wait;
}