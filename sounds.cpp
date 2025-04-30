#include "sounds.h"
//g++ -std=c++11 sounds.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -I/usr/local/opt/sfml@2/include -L/usr/local/opt/sfml@2/lib
void Sound::loadSound(std::string soundName)
{
    sf::SoundBuffer buffer;
                if (!buffer.loadFromFile(soundName))
                    {return -1;}
                sf::Sound sound(buffer);
}
// void Sound::playSound()
// {
//     sound.play();
// }
    