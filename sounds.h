#ifndef SOUNDS_H
#define SOUNDS_H
#include <string>
#include <SFML/Audio.hpp>
class Sound
{
public:
    void loadSound(std::string soundName);
    void playSound();


private:

};


#endif