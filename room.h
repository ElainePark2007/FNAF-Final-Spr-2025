#ifndef ROOM_H
#define ROOM_H
#include <SFML/Graphics.hpp>
#include "animatronic.h"

class Room {
public:
    Room(const sf::Texture &defaultTexture, const sf::Texture &animatronicTexture, std::string name);
    void setRoomName(std::string name);
    void switchAnimatronicState();

    std::string getRoomName();




private:
    sf::Texture mDefaultState;
    sf::Texture mAnimatronicState;
    sf::RectangleShape mStateShown;
    std::string mRoomName;
    bool animatronicPresent;



};





#endif