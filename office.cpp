#include "office.h"


Office::Office(std::string textureName, std::string name, int defaultFrame)
{
    sf::IntRect defaultTexture(0, 2*(defaultFrame+1)+720*(defaultFrame-1), 1600, 720);
    sf::IntRect leftTexture(0, 2*(4)+720*(2), 1600, 720);
    sf::IntRect rightTexture(0, 2*(5)+720*(3), 1600, 720);

    if(!mDefaultState.loadFromFile(textureName, defaultTexture)) {
        std::cerr<<"Error loading texture\n";
        exit(1);
    }
    mStateShown.setTexture(mDefaultState);
    mRoomName=name;
}

sf::Sprite Office::getRoomPicture()
{
    return mStateShown;
}