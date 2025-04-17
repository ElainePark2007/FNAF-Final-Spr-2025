#ifndef ANIMATRONIC_H
#define ANIMATRONIC_H
#include <iostream>

class Animatronic {

public:
    Animatronic(int ai);
    int getAiLevel();
    std::string getLocation();

    void setAiLevel(int ai);
    void setLocation(std::string location);

    void aiIncrease();
    void movementOpportunity(int ai);
    void moveRooms();



private:
    int mAiLevel;
    std::string mLocation;


    
};


#endif