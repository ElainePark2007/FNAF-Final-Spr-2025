#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Animation {

public:
    Animation(std::string animationFile);
    void runAnimation();
    sf::Sprite getSprite();

private:
    int currentFrame, numFrames, width, height, offset;
    sf::Texture mAnimationTexture;
    sf::Sprite mAnimatronic;
    sf::Clock mClock;
};



#endif