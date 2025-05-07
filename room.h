/**
 * @file room.h
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Room class declaration file
 * @date 2025-05-06
 */
#ifndef ROOM_H
#define ROOM_H
#include <SFML/Graphics.hpp>

class Room {
public:
    Room(std::string textureName, std::string name, int defaultFrame, int animatronicFrame);
    void setRoomName(std::string name);
    void switchAnimatronicState();
    void switchToAnimatronicState();
    void setNextRoom(Room &next);

    std::string getRoomName();
    sf::Sprite getRoomPicture();
    bool getAnimatronicState();
    Room* getNextRoom();






private:
    sf::Texture mDefaultState;
    sf::Texture mAnimatronicState;
    sf::Sprite mStateShown;
    std::string mRoomName;
    bool animatronicPresent;
    Room* nextRoom;



};





#endif