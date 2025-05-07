/**
 * @file office.h
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Office class declaration file
 * @version 0.1
 * @date 2025-05-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef OFFICE_H
#define OFFICE_H
#include "room.h"

class Office{
public:
    Office(std::string textureName, std::string name, int defaultFrame);
    sf::Sprite getRoomPicture();
    void turnLeftLightOn();
    void turnRightLightOn();


private:
    sf::Texture mDefaultState;
    sf::Texture leftLightOn;
    sf::Texture rightLightOn;
    sf::Sprite mStateShown;
    std::string mRoomName;
    bool leftLight, rightLight;




};



#endif