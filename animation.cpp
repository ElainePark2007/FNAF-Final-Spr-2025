#include "animation.h"

Animation::Animation(std::string animationFile)
{
    if(!mAnimationTexture.loadFromFile(animationFile)) {
        std::cerr<<"Error opening texture\n";
        exit(1);
    }
    mAnimatronic.setTexture(mAnimationTexture);
    height=720;
    width=1600;
    offset=2;
    numFrames=16;
    currentFrame=1;
}

void Animation::runAnimation()
{
    if(mClock.getElapsedTime().asMilliseconds()>30) {
        mAnimatronic.setTextureRect(sf::IntRect(0, height*(currentFrame)+(offset*currentFrame), width, height));
        currentFrame=(currentFrame+1)%numFrames;
        mClock.restart();
    }
}

sf::Sprite Animation::getSprite()
{
    return mAnimatronic;
}