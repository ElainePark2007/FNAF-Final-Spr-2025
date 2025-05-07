/**
 * @file room.cpp
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Room class definition file
 * @date 2025-05-06
 */
#include <iostream>
#include "room.h"

/**
 * @brief Construct a new Room:: Room object
 * 
 * @param textureName Texture file for room
 * @param name Name of room
 * @param defaultFrame Frame for default texture
 * @param animatronicFrame Frame for animatronic texture
 */
Room::Room(std::string textureName, std::string name, int defaultFrame, int animatronicFrame)
{
    sf::IntRect defaultTexture(0, 2*(defaultFrame)+720*(defaultFrame-1), 1600, 720);
    sf::IntRect animatronicTexture(0, 2*(animatronicFrame)+720*(animatronicFrame-1), 1600, 720);

    if(!mDefaultState.loadFromFile(textureName, defaultTexture) || !mAnimatronicState.loadFromFile(textureName,animatronicTexture)) {
        std::cerr<<"Error loading texture\n";
        exit(1);
    }
    mStateShown.setTexture(mDefaultState);
    mRoomName=name;
    animatronicPresent=false;
    nextRoom=nullptr;
}

/**
 * @brief Sets name of room
 * 
 * @param name Room name
 */
void Room::setRoomName(std::string name)
{
    mRoomName=name;
}

/**
 * @brief Switches the current animatronic state
 * 
 */
void Room::switchAnimatronicState()
{
    if(animatronicPresent) {
        animatronicPresent=false;
        mStateShown.setTexture(mDefaultState);
    } else {
        animatronicPresent=true;
        mStateShown.setTexture(mAnimatronicState);
    }
}

/**
 * @brief Gets name of room
 * 
 * @return std::string Name of room
 */
std::string Room::getRoomName()
{
    return mRoomName;
}

/**
 * @brief Gets current state of room
 * 
 * @return sf::Sprite Current room texture
 */
sf::Sprite Room::getRoomPicture()
{
    return mStateShown;
}

/**
 * @brief Switches directly to animatronic state
 * 
 */
void Room::switchToAnimatronicState()
{
    animatronicPresent=true;
    mStateShown.setTexture(mAnimatronicState);
}

/**
 * @brief Sets next room variable
 * 
 * @param next Next room
 */
void Room::setNextRoom(Room &next)
{
    nextRoom=&next;
}

/**
 * @brief Returns current animatronic state
 * 
 * @return true Animatronic is present
 * @return false Animatronic is not present
 */
bool Room::getAnimatronicState()
{
    return animatronicPresent;
}

/**
 * @brief Returns address of next room
 * 
 * @return Room* Next room
 */
Room* Room::getNextRoom()
{
    return nextRoom;
}