#ifndef SOUNDS_H
#define SOUNDS_H
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Sound
{
public:
    Sound();
    ~Sound();
    bool loadSound(const std::string &soundName);
    void playSound();


private:
    sf::Sound sound;
    sf::SoundBuffer buffer;
};


#endif