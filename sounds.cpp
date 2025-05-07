/**
 * @file sounds.cpp
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Sounds class definition file
 * @date 2025-05-07
 */
#include "sounds.h"
//g++ -std=c++11 *.cpp -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -I/usr/local/opt/sfml@2/include -L/usr/local/opt/sfml@2/lib
/**
 * @brief Construct a new Sound:: Sound object
 * 
 */
Sound::Sound()
{
}

/**
 * @brief Destroy the Sound:: Sound object
 * 
 */
Sound::~Sound()
{
}

/**
 * @brief Loads sound from file
 * 
 * @param file Sound file
 * @return true Sound loaded correctly
 * @return false Sound did not load correctly
 */
bool Sound::loadSound(const std::string &file)
{
    if (!buffer.loadFromFile(file))
    {
       return false;
    }
    sound.setBuffer(buffer);
    return true;
}

/**
 * @brief Plays selected sound
 * 
 */
void Sound::playSound()
{
    sound.play();
}

/**
 * @brief Sets volume of sound
 * 
 * @param v Volume setting
 */
void Sound::volume(int v)
{
    sound.setVolume(v);
}

/**
 * @brief Loops sound
 * 
 */
void Sound::loop()
{
    sound.setLoop(true);
}

/**
 * @brief Stops sound
 * 
 */
void Sound::stopSound()
{
    sound.stop();
}

/**
 * @brief Gets status of sound
 * 
 * @return true Sound was stopped
 * @return false Sound was not stopped
 */
bool Sound::getStatus() {
    if (sound.getStatus()==sf::SoundSource::Status::Stopped)
    {
        return true;
    }
    return false;
}
//example for how to load sound sound if need be
// std::string l = "pigeons-flying-6351.mp3";
//     sf::SoundBuffer buffer;
//                 if (!buffer.loadFromFile(l))
//                     {return -1;}
//                 sf::Sound sound(buffer);
    