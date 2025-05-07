/**
 * @file office.cpp
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Office class definition file
 * @version 0.1
 * @date 2025-05-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "office.h"

/**
 * @brief Construct a new Office:: Office object
 * 
 * @param textureName Texture file for office room
 * @param name Name of room
 * @param defaultFrame Frame for default texture
 */
Office::Office(std::string textureName, std::string name, int defaultFrame)
{
    sf::IntRect defaultTexture(0, 2*(defaultFrame)+720*(defaultFrame-1), 1600, 720);
    sf::IntRect leftTexture(0, 2*(4)+720*(2), 1600, 720);
    sf::IntRect rightTexture(0, 2*(5)+720*(3), 1600, 720);

    if(!mDefaultState.loadFromFile(textureName, defaultTexture)) {
        std::cerr<<"Error loading texture\n";
        exit(1);
    }
    mStateShown.setTexture(mDefaultState);
    mRoomName=name;
    leftLight=false;
    rightLight=false;
}

/**
 * @brief Returns current state of the room
 * 
 * @return sf::Sprite Current state
 */
sf::Sprite Office::getRoomPicture()
{
    return mStateShown;
}

/**
 * @brief Switches to left light texture
 * 
 */
void Office::turnLeftLightOn()
{
    leftLight=true;
    if(rightLight) {
        rightLight=false;
    }
    mStateShown.setTexture(leftLightOn);
}

/**
 * @brief Switches to right light texture
 * 
 */
void Office::turnRightLightOn()
{
    rightLight=true;
    if(leftLight) {
        leftLight=false;
    }
    mStateShown.setTexture(rightLightOn);
}