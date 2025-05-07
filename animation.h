/**
 * @file animation.h
 * @author Matteo Coppola
 * @brief Animation class declaration file
 * @date 2025-05-05
 */
#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Animation {

public:
    Animation(std::string animationFile, int frameCount, int frameWidth);
    void runAnimation();
    void runAnimationOnce();
    void startOnce();
    sf::Sprite getSprite();

private:
    int currentFrame, numFrames, width, height, offset;
    bool isPlaying = false;
    int framesPlayed;
    sf::Texture mAnimationTexture;
    sf::Sprite mAnimatronic;
    sf::Clock mClock;
};



#endif