#include "sounds.h"
//g++ -std=c++11 main.cpp sounds.cpp room.cpp button.cpp -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -I/usr/local/opt/sfml@2/include -L/usr/local/opt/sfml@2/lib
Sound::Sound()
{
}
Sound::~Sound()
{
}
bool Sound::loadSound(const std::string &file)
{
    if (!buffer.loadFromFile(file))
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
void Sound::volume(int v)
{
    sound.setVolume(v);
}
void Sound::loop()
{
    sound.setLoop(true);
}
void Sound::stopSound()
{
    sound.stop();
}
//example for how to load sound sound if need be
// std::string l = "pigeons-flying-6351.mp3";
//     sf::SoundBuffer buffer;
//                 if (!buffer.loadFromFile(l))
//                     {return -1;}
//                 sf::Sound sound(buffer);
    