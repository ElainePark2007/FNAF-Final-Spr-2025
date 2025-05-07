/**
 * @file animation.cpp
 * @author Matteo Coppola
 * @brief Animation class definition file
 * @date 2025-05-05
 */
#include "animation.h"

/**
 * @brief Construct a new Animation:: Animation object
 * 
 * @param animationFile Name of png with animation
 * @param frameCount Number of frames in png
 * @param frameWidth Width of each frame
 */
Animation::Animation(std::string animationFile, int frameCount, int frameWidth)
{
    if(!mAnimationTexture.loadFromFile(animationFile)) {
        std::cerr<<"Error opening texture\n";
        exit(1);
    }
    mAnimatronic.setTexture(mAnimationTexture);
    height=720;
    width=frameWidth;
    offset=2;
    numFrames=frameCount;
    currentFrame=1;
}

/**
 * @brief Updates object with current frame
 * 
 */
void Animation::runAnimation()
{
    if(mClock.getElapsedTime().asMilliseconds()>30) {
        mAnimatronic.setTextureRect(sf::IntRect(0, 2*(currentFrame+1)+height*currentFrame, width, height));
        currentFrame=(currentFrame+1)%numFrames;
        mClock.restart();
    }
}
/**
 * @brief combined with start once it plays the animation cycle one time, only used for Foxy
 * 
 */
void Animation::runAnimationOnce()
{
    if (!isPlaying)
        return;

    if (mClock.getElapsedTime().asMilliseconds() > 30) {
        mAnimatronic.setTextureRect(sf::IntRect(0, 2*(currentFrame+1)+height*currentFrame, width, height));
        currentFrame++;
        framesPlayed++;
        mClock.restart();

        if (framesPlayed >= numFrames) {
            isPlaying = false;
            currentFrame = 0;
            framesPlayed = 0;
        }
    }
}

void Animation::startOnce()
{
    if (!isPlaying) {
        isPlaying = true;
        currentFrame = 0;
        framesPlayed = 0;
        mClock.restart();
    }
}


/**
 * @brief Returns current state of sprite (used for actually printing to window)
 * 
 * @return sf::Sprite Current state of sprite
 */
sf::Sprite Animation::getSprite()
{
    return mAnimatronic;
}