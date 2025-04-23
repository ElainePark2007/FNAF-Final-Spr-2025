#ifndef ANIMATRONIC_H
#define ANIMATRONIC_H
#include <iostream>
#include <cstdlib>
#include <ctime>



class Animatronic {

public:
    Animatronic(int ai);
    int const getAiLevel();
    std::string const getLocation();

    void setAiLevel(int ai);
    void setLocation(std::string location);

    void aiIncrease();
    void movementOpportunity();
    void moveRooms();



private:
    int mAiLevel;
    std::string mLocation;


    
};


#endif