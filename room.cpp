#include <iostream>
#include "room.h"

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

void Room::setRoomName(std::string name)
{
    mRoomName=name;
}

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

std::string Room::getRoomName()
{
    return mRoomName;
}

sf::Sprite Room::getRoomPicture()
{
    return mStateShown;
}

void Room::switchToAnimatronicState()
{
    animatronicPresent=true;
    mStateShown.setTexture(mAnimatronicState);
}

void Room::setNextRoom(Room &next)
{
    nextRoom=&next;
}

bool Room::getAnimatronicState()
{
    return animatronicPresent;
}

Room* Room::getNextRoom()
{
    return nextRoom;
}