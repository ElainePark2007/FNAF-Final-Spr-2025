/**
 * @file main.cpp
 * @author Matteo Coppola, Luke Kellner, Elaine Park
 * @brief Main game file
 * @date 2025-05-07
 */
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "animatronic.h"
#include "animation.h"
#include "sounds.h"
#include "room.h"
#include "button.h"
#include "office.h"

int main()
{
    std::srand(std::time(NULL));

    int power=999;
    bool bonnieScareTriggered = false, foxyScareTriggered=false, chicaScareTriggered=false, freddyScareTriggered=false;
    bool bonnieOffice=false, foxyOffice=false, chicaOffice=false, freddyOffice=false;
    bool jumpscare = false;
    bool gameOver=false;
    bool staticPlayed=false;
    sf::Clock clock;
    Animation bonnieScare("Animations/bonnieAnimation (w1600, f11).png", 11, 1600);
    Animation freddyScare("Animations/freddyAnimation (w1600, f22).png", 22, 1600);
    Animation chicaScare("Animations/chicaAnimation (w1600, f16).png", 16, 1600);
    Animation foxyScare("Animations/foxyAnimation (w1600, f21).png", 21, 1600);
    Animation endingScreen("Animations/endingScreen (w1600, f8).png", 8, 1600);

    sf::Clock foxyClock;
    sf::Clock otherClock;

    

    sf::Texture cameraTexture;
    cameraTexture.loadFromFile("cameraUI2.png");
    sf::Sprite cameraMenu;
    cameraMenu.setTexture(cameraTexture);
    cameraMenu.setPosition(1150, 345);

    std::vector<Room> allRooms;
    std::vector<Button> cameraButtons;

    Room room1("rooms/showStage.png", "Show Stage", 7, 1);
    Room room2("rooms/diningArea.png", "Dining Area", 1, 2);
    Room room3("rooms/backstage.png", "Backstage", 1, 4);
    Room room4("rooms/pirate'sCove.png", "Pirate's Cove", 4, 2);
    Room room5("rooms/supplyCloset.png", "Supply Closet", 1, 2);
    Room room6("rooms/westHallA.png", "West Hall A", 1, 2);
    Room room7("rooms/westHallB.png", "West Hall B", 1, 6);
    Room room8("rooms/restrooms.png", "Restrooms", 1, 3);
    Room room9("rooms/eastHall.png", "East Hall A", 1, 6);
    Room room10("rooms/eastHall.png", "East Hall B", 7, 15);
    Room room11("rooms/kitchen.png", "Kitchen", 1, 1);

    Office office("rooms/theOffice.png", "The Office", 1);

    allRooms.push_back(room1);
    allRooms.push_back(room2);
    allRooms.push_back(room3);
    allRooms.push_back(room4);
    allRooms.push_back(room5);
    allRooms.push_back(room6);
    allRooms.push_back(room7);
    allRooms.push_back(room8);
    allRooms.push_back(room9);
    allRooms.push_back(room10);
    allRooms.push_back(room11);
    allRooms[0].setNextRoom(allRooms[1]);
    allRooms[1].setNextRoom(allRooms[2]);
    allRooms[2].setNextRoom(allRooms[5]);
    allRooms[4].setNextRoom(allRooms[6]);
    allRooms[5].setNextRoom(allRooms[4]);
    //Add if in room7 and animatronic moves, then jumpscare unless door closed
    allRooms[7].setNextRoom(allRooms[8]);
    allRooms[8].setNextRoom(allRooms[9]);
    //Add if in room9 and animatronic moves, then jumpscare unless door closed

    Animatronic foxy(0, allRooms[3]);
    Animatronic freddy(4, allRooms[0]);
    Animatronic bonnie(4, allRooms[0]);
    Animatronic chica(4, allRooms[7]);

    cameraButtons.push_back(Button ("", sf::Vector2f(1323, 373), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1303, 429), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1197, 456), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1271, 507), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1239, 605), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1323, 623), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1323, 663), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1535, 457), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1429, 624), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1429, 664), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1526, 588), sf::Vector2f(53, 32), sf::Color::Transparent));
    
    bool cameraOpen=false, leftDoorClosed=false, rightDoorClosed=false, introDone=false;
    bool mouseInButton=false;
    int currentRoom=0;

   
    sf::RenderWindow window(sf::VideoMode(1600, 720), "Five Nights at Freddy's");
    sf::Texture texture;
    if (!texture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }

    //set initial call and ambience to follow
    bool ambiencePlaying = false;
    sf::Music music;
    if (!music.openFromFile("musicFiles/Ambience 2.wav"))
    {
    }
    sf::Music call;
    if (!call.openFromFile("musicFiles/Voiceover1c.wav"))
    {
    }
    call.setPosition(0, 1, 10); // change its 3D position
    call.setVolume(100); 
    // Change some parameters
    music.setPosition(0, 1, 10); // change its 3D position
    music.setVolume(100);         // reduce the volume
    //music.setLoop(true);         // make it loop
    
    // Play it
    call.play();
    //create sound objects
    Sound camOff;
    Sound windowScare;
    Sound knock;
    Sound camSwitch;
    Sound scareOne;
    Sound scareTwo;
    Sound camOn;
    Sound fan;
    Sound door;
    Sound laughOne;
    Sound endStatic;
    Sound win;
    //load sounds
    camOff.loadSound("soundFiles/Put Down.wav");
    windowScare.loadSound("soundFiles/Windowscare.wav");
    knock.loadSound("soundFiles/Knock2.wav");
    camSwitch.loadSound("soundFiles/Blip3.wav");
    scareOne.loadSound("soundFiles/Xscream.wav");
    scareTwo.loadSound("soundFiles/Xscream2.wav");
    camOn.loadSound("soundFiles/Camera Video Load.wav");
    fan.loadSound("soundFiles/Buzz Fan Florescent2.wav");
    door.loadSound("soundFiles/Door.wav");
    laughOne.loadSound("soundFiles/Laugh1.wav");
    endStatic.loadSound("soundFiles/Static.wav");
    win.loadSound("soundFiles/Win.wav");
    
    camOff.volume(5);
    camOn.volume(5);
    camSwitch.volume(5);
    scareOne.volume(5);
    door.volume(5);
    laughOne.volume(5);
    endStatic.volume(5);
    win.volume(5);
    scareTwo.volume(5);
    knock.volume(5);
    windowScare.volume(5);
    fan.volume(1);
    fan.loop();
    fan.playSound();

    sf::Texture intro;
    sf::Sprite introSprite;
    if(!intro.loadFromFile("introStuff.png", sf::IntRect(0, 2890, 1600, 720))) {
        std::cerr<<"Error loading intro texture\n";
        exit(1);
    }
    introSprite.setTexture(intro);

    sf::Texture outro;
    sf::Sprite outroSprite;
    if(!outro.loadFromFile("introStuff.png", sf::IntRect(0, 4334, 1600, 720))) {
        std::cerr<<"Error loading intro texture\n";
        exit(1);
    }
    outroSprite.setTexture(outro);
    
    sf::Clock gameStarted;
    sf::Clock jumpNoise;
    while (window.isOpen())
    {
        
        sf::Vector2i mPos;
        sf::Vector2f mousePosition;
        float elapsed = clock.getElapsedTime().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            mPos = sf::Mouse::getPosition(window);
            mousePosition = window.mapPixelToCoords(mPos);
            
            if(event.type==sf::Event::KeyPressed) {
                if(event.key.code==sf::Keyboard::C) {
                    if(cameraOpen) {
                        cameraOpen=false;
                        camOff.playSound();
                    } else {
                        cameraOpen=true;
                        camOn.playSound();
                    }
                }
            }
        }

        
        while(gameStarted.getElapsedTime().asSeconds()<5) {
            window.draw(introSprite);
            window.display();
            otherClock.restart();
            foxyClock.restart();
        }

        window.clear();
        if(cameraOpen) {
            window.draw(allRooms[currentRoom].getRoomPicture());
            window.draw(cameraMenu);

            for(int i=0; i<11; i++)
            {
                window.draw(cameraButtons[i]);
                if(event.type==sf::Event::MouseButtonPressed) {
                    mouseInButton =    mousePosition.x >= cameraButtons[i].getPosition().x - cameraButtons[i].getDimensions().x
                    && mousePosition.x <= cameraButtons[i].getPosition().x + cameraButtons[i].getDimensions().x
                    && mousePosition.y >= cameraButtons[i].getPosition().y - cameraButtons[i].getDimensions().y
                    && mousePosition.y <= cameraButtons[i].getPosition().y + cameraButtons[i].getDimensions().y;
                
                    if(mouseInButton) {
                        currentRoom=i;
                        if(i==3) {
                            foxyClock.restart();
                        }
                        if(chica.getLocation()==&allRooms[9] && i==9) {
                            windowScare.playSound();

                            sf::Clock ending;
                            while(ending.getElapsedTime().asMilliseconds()<500)
                            {
                                window.clear();
                                endingScreen.runAnimation();
                                window.draw(endingScreen.getSprite());
                                window.display();
                                if (!staticPlayed)
                                {
                                    endStatic.playSound();
                                    staticPlayed=true;
                                }
                            }
                            chicaOffice=false;
                            chica.setLocation(allRooms[7]);
                        }
                        if(bonnie.getLocation()==&allRooms[6] && i==6) {
                            windowScare.playSound();

                            sf::Clock ending;
                            while(ending.getElapsedTime().asMilliseconds()<500)
                            {
                                window.clear();
                                endingScreen.runAnimation();
                                window.draw(endingScreen.getSprite());
                                window.display();
                                if (!staticPlayed)
                                {
                                    endStatic.playSound();
                                    staticPlayed=true;
                                }
                            }
                            bonnieOffice=false;
                            bonnie.setLocation(allRooms[0]);
                        }
                        if(freddy.getLocation()==&allRooms[6] && i==6) {
                            windowScare.playSound();

                            sf::Clock ending;
                            while(ending.getElapsedTime().asMilliseconds()<500)
                            {
                                window.clear();
                                endingScreen.runAnimation();
                                window.draw(endingScreen.getSprite());
                                window.display();
                                if (!staticPlayed)
                                {
                                    endStatic.playSound();
                                    staticPlayed=true;
                                }
                            }
                            freddyOffice=false;
                            freddy.setLocation(allRooms[0]);
                        }
                        camSwitch.playSound();
                        mouseInButton=false;
                    }
                }
            }

        } else {
            window.draw(office.getRoomPicture());
        }
        float i = elapsed;

        if(foxyClock.getElapsedTime().asSeconds()>=30)// time until foxy scares
        {
            cameraOpen=false;
            jumpscare=true;
            foxyScareTriggered=true;
        }
        
        if(otherClock.getElapsedTime().asSeconds()>=5) {
            if(freddy.movementOpportunity(freddyOffice) && !rightDoorClosed) {
                cameraOpen=false;
                jumpscare=true;
                freddyScareTriggered=true;
            }
            if(bonnie.movementOpportunity(bonnieOffice) && !leftDoorClosed) {
                cameraOpen=false;
                jumpscare=true;
                bonnieScareTriggered=true;
            }
            if(chica.movementOpportunity(chicaOffice) && !leftDoorClosed) {
                cameraOpen=false;
                jumpscare=true;
                chicaScareTriggered=true;
            }
            otherClock.restart();
        }
        if(jumpscare)
        {
            while (foxyScareTriggered)
            {
                static bool soundPlayed = false;
                
                if (!soundPlayed) {
                    scareOne.playSound();
                    fan.stopSound();
                    music.stop();
                    call.stop();
                    soundPlayed = true;
                }
                static bool foxyOnce=true;
                if (foxyOnce) {
                    foxyScare.startOnce(); 
                    foxyOnce = false;          
                }
                
                foxyScare.runAnimationOnce();
                window.clear();
                // foxyScare.runAnimation();
                window.draw(foxyScare.getSprite());
                window.display();
                if (jumpNoise.getElapsedTime().asSeconds() >=2) //number is how many seconds jumpscare lasts
                {
                    scareOne.stopSound();
                }
                if (soundPlayed && scareOne.getStatus() == true) {
                    sf::Clock ending;
                    while(ending.getElapsedTime().asSeconds()<3)
                    {
                        window.clear();
                        endingScreen.runAnimation();
                        window.draw(endingScreen.getSprite());
                        window.display();
                        if (!staticPlayed)
                        {
                            endStatic.playSound();
                            staticPlayed=true;
                        }
                    }
                    window.close();
                    break;
                }
            }

            while (bonnieScareTriggered)
            {
                static bool soundPlayed = false;
                
                if (!soundPlayed) {
                    scareTwo.playSound();
                    fan.stopSound();
                    music.stop();
                    call.stop();
                    soundPlayed = true;
                }
                window.clear();
                bonnieScare.runAnimation();
                window.draw(bonnieScare.getSprite());
                window.display();
                if (jumpNoise.getElapsedTime().asSeconds() >=3)
                {
                    scareTwo.stopSound();
                }
                if (soundPlayed && scareTwo.getStatus() == true) {
                    sf::Clock ending;
                    while(ending.getElapsedTime().asSeconds()<3)
                    {
                        window.clear();
                        endingScreen.runAnimation();
                        window.draw(endingScreen.getSprite());
                        window.display();
                        if (!staticPlayed)
                        {
                            endStatic.playSound();
                            staticPlayed=true;
                        }
                    }
                    window.close();
                    break;
                }
            }

            while (freddyScareTriggered)
            {
                static bool soundPlayed = false;
                
                if (!soundPlayed) {
                    scareTwo.playSound();
                    fan.stopSound();
                    music.stop();
                    call.stop();
                    soundPlayed = true;
                }
                window.clear();
                freddyScare.runAnimation();
                window.draw(freddyScare.getSprite());
                window.display();
                if (jumpNoise.getElapsedTime().asSeconds() >=3)
                {
                    scareTwo.stopSound();
                }
                if (soundPlayed && scareTwo.getStatus() == true) {
                    sf::Clock ending;
                    while(ending.getElapsedTime().asSeconds()<3)
                    {
                        window.clear();
                        endingScreen.runAnimation();
                        window.draw(endingScreen.getSprite());
                        window.display();
                        if (!staticPlayed)
                        {
                            endStatic.playSound();
                            staticPlayed=true;
                        }
                    }
                    window.close();
                    break;
                }
            }

            while (chicaScareTriggered)
            {
                static bool soundPlayed = false;
                
                if (!soundPlayed) {
                    scareTwo.playSound();
                    fan.stopSound();
                    music.stop();
                    call.stop();
                    soundPlayed = true;
                }
                window.clear();
                chicaScare.runAnimation();
                window.draw(chicaScare.getSprite());
                window.display();
                if (jumpNoise.getElapsedTime().asSeconds() >=3)
                {
                    scareTwo.stopSound();
                }
                if (soundPlayed && scareTwo.getStatus() == true) {
                    sf::Clock ending;
                    while(ending.getElapsedTime().asSeconds()<3)
                    {
                        window.clear();
                        endingScreen.runAnimation();
                        window.draw(endingScreen.getSprite());
                        window.display();
                        if (!staticPlayed)
                        {
                            endStatic.playSound();
                            staticPlayed=true;
                        }
                    }
                    window.close();
                    break;
                }
            }
        }

        if (call.getStatus()==sf::Music::Stopped && !ambiencePlaying)
        {
            music.play();
            ambiencePlaying=true;
        }

        if (gameStarted.getElapsedTime().asSeconds()>90)
        {
            fan.stopSound();
            music.stop();
            call.stop();
            foxyClock.restart();
            otherClock.restart();
            sf::Clock temp;
            win.playSound();
            while(temp.getElapsedTime().asSeconds()<10) {
                window.draw(outroSprite);
                window.display();
            }
            window.close();
        }

        window.display();
        jumpNoise.restart();
    }
    return 0;

}