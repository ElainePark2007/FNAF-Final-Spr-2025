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