#ifndef ANIMATRONIC_H
#define ANIMATRONIC_H
#include <iostream>
#include "room.h"




class Animatronic {

public:
    Animatronic(int ai, Room &location);
    int const getAiLevel();
    Room* const getLocation();

    void setAiLevel(int ai);
    void setLocation(Room location);

    void aiIncrease();
    bool movementOpportunity(bool &jumpscare);
    bool moveRooms(bool &jumpscare);

private:
    int mAiLevel;
    Room* mLocation;


    
};


#endif