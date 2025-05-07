/**
 * @file animatronic.h
 * @author Matteo Coppola
 * @brief Animatronic class declaration file
 * @date 2025-05-06
 */
#ifndef ANIMATRONIC_H
#define ANIMATRONIC_H
#include <iostream>
#include <thread>

using namespace std::chrono;




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