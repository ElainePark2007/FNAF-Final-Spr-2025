#include "sounds.h"
//g++ -std=c++11 main.cpp sounds.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -I/usr/local/opt/sfml@2/include -L/usr/local/opt/sfml@2/lib
Sound::Sound()
{
}
Sound::~Sound()
{
}
bool Sound::loadSound(const std::string &soundName)
{
    if (!buffer.loadFromFile(soundName))
    {
       return false;
    }
    sound.setBuffer(buffer);
    return true;
}
void Sound::playSound()
{
    sound.play();
}
//example for how to load sound sound if need be
// std::string l = "pigeons-flying-6351.mp3";
//     sf::SoundBuffer buffer;
//                 if (!buffer.loadFromFile(l))
//                     {return -1;}
//                 sf::Sound sound(buffer);
    