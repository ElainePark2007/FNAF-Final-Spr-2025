#include <iostream>
#include "room.h"

Room::Room(const sf::Texture &defaultTexture, const sf::Texture &animatronicTexture, std::string name)
{
    mDefaultState=defaultTexture;
    mAnimatronicState=animatronicTexture;
    mStateShown.setTexture(&defaultTexture);
    mRoomName=name;
    animatronicPresent=false;
}

void Room::setRoomName(std::string name)
{
    mRoomName=name;
}

void Room::switchAnimatronicState()
{
    if(animatronicPresent) {
        animatronicPresent=false;
        mStateShown.setTexture(&mDefaultState);
    } else {
        animatronicPresent=true;
        mStateShown.setTexture(&mAnimatronicState);
    }
}

std::string Room::getRoomName()
{
    return mRoomName;
}