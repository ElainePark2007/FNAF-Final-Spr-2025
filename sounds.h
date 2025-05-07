/**
 * @file sounds.h
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Sound class declaration file
 * @date 2025-05-07
 */
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
    bool loadSound(const std::string &file);
    void playSound();
    void volume(int v);
    void loop();
    void stopSound();
    bool getStatus();

private:
    sf::Sound sound;
    sf::SoundBuffer buffer;
};


#endif