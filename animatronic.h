#ifndef ANIMATRONIC_H
#define ANIMATRONIC_H
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

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

    void timer();
    void timerLength(int wait);

private:
    int mAiLevel;
    std::string mLocation;
    int mWait;

    
};


#endif