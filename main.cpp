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
    //Animatronic freddy(1);
    //Animatronic bonnie(3);
    //Animatronic chica(3);
    //Animatronic foxy(2);
    bool bonnieScareTriggered = false, foxyScareTriggered=false, chicaScareTriggered=false, freddyScareTriggered=false;
    bool jumpscare = false;
    bool gameOver=false;
    sf::Clock clock;
    Animation bonnieScare("Animations/bonnieAnimation (w1600, f11).png", 11, 1600);
    Animation freddyScare("Animations/freddyAnimation (w1600, f22).png", 22, 1600);
    Animation chicaScare("Animations/chicaAnimation (w1600, f16).png", 16, 1600);
    Animation foxyScare("Animations/foxyAnimation (w1600, f21).png", 21, 1600);
    Animation endingScreen("Animations/endingScreen (w1600, f8).png", 8, 1600);

    Animatronic foxy(0);
    Animatronic freddy(3);
    Animatronic bonnie(3);
    Animatronic chica(3);
    sf::Clock foxyClock;
    sf::Clock freddyClock;
    sf::Clock bonnieClock;
    sf::Clock chicaClock;

    

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
    
    bool cameraOpen=false;
    bool mouseInButton;
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
    //load sounds
    camOff.loadSound("soundFiles/Put Down.wav");
    windowScare.loadSound("soundFiles/Windowscare.wav");
    knock.loadSound("soundFiles/Knock2.wav");
    camSwitch.loadSound("soundFiles/Blip3.wav");
    scareOne.loadSound("soundFiles/Xscream.wav");
    scareTwo.loadSound("soundFiles/Xscream2.wav");
    camOn.loadSound("soundFiles/Camera Video Load.wav");
    fan.loadSound("soundFiles/Buzz Fan Florescent2.wav");
    fan.volume(5);
    fan.loop();
    fan.playSound();
    
    
    //create sprite that look like a button
    sf::Sprite button(texture);
    
    //get size of image
    sf::Vector2u imageSize=texture.getSize();
    //change origin to the center of the image (makes rotation easy)
    button.setOrigin(imageSize.x/2, imageSize.y/2);
    //set position
    sf::Vector2f position={300,200};
    button.setPosition(position.x,position.y);
    //choose color
    button.setColor(sf::Color(0, 0, 255));
    //set size as a ration of original size
    button.setScale(0.5,0.5);
    //Make label
    sf::Font font;
    if (!font.loadFromFile("college.ttf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    sf::Text text;
    text.setFont(font);
    //choose the font size based on button size (I choose half)
    unsigned int fontSize = button.getGlobalBounds().height/2;
    text.setCharacterSize(fontSize);
    //set label
    text.setString("Push me!");
    //set origin to the middle
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
    //set position at the middle of the button
    text.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    sf::Color textNormal = sf::Color::Green;
    sf::Color textHover = sf::Color::Red;
    text.setFillColor(textNormal);
    while (window.isOpen())
    {
        float elapsed = clock.getElapsedTime().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            //get position of the mouse
            //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2i mPos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
            bool mouseInButton;
            if(event.type == sf::Event::MouseMoved)
            {
                if(mouseInButton)
                {
                    text.setFillColor(textHover);
                }
                else
                {
                    text.setFillColor(textNormal);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        button.setRotation(180);
                    }
                    else
                    {
                        button.setRotation(0);
                    }
                }
                
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button==sf::Mouse::Left)
                {
                    if(mouseInButton)
                    {
                        text.setFillColor(textHover);
                        button.setRotation(0);
                    }
                    else
                    {
                        text.setFillColor(textNormal);
                        button.setRotation(0);
                    }
                }
            }
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
        sf::Vector2i mPos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);

        
        window.clear();
        
        if(cameraOpen) {
            window.draw(allRooms[currentRoom].getRoomPicture());
            window.draw(cameraMenu);
            for(int i=0; i<11; i++)
            {
                window.draw(cameraButtons[i]);
            }

            for(int i=0; i<11; i++)
            {
                if(event.type==sf::Event::MouseButtonPressed) {
                    mouseInButton =    mousePosition.x >= cameraButtons[i].getPosition().x - cameraButtons[i].getDimensions().x
                    && mousePosition.x <= cameraButtons[i].getPosition().x + cameraButtons[i].getDimensions().x
                    && mousePosition.y >= cameraButtons[i].getPosition().y - cameraButtons[i].getDimensions().y
                    && mousePosition.y <= cameraButtons[i].getPosition().y + cameraButtons[i].getDimensions().y;
                
                    if(mouseInButton) {
                        currentRoom=i;
                        if(i=4) {
                            foxyClock.restart();
                        }
                        camSwitch.playSound();
                    }
                }
            }

        } else {
            window.draw(office.getRoomPicture());
        }
        float i = elapsed;
        // if (elapsed >= 35.f && !bonnieScareTriggered)
        // {
        //     jumpscare = true;
        //     cameraOpen=false;
        //     bonnieScareTriggered=true;
        // }
        if(foxyClock.getElapsedTime().asSeconds()>=15) {
            //jumpscare=true;
            cameraOpen=false;
            foxyScareTriggered=true;
        }

        if (foxyScareTriggered)
        {
            static bool soundPlayed = false;
            
            if (!soundPlayed) {
                scareOne.playSound();
                fan.stopSound();
                music.stop();
                call.stop();
                soundPlayed = true;
            }
            foxyScare.runAnimation();
            window.draw(foxyScare.getSprite());
            if (soundPlayed && scareOne.getStatus() == true) {
                sf::Clock ending;
                while(ending.getElapsedTime().asSeconds()<3)
                {
                    window.clear();
                    endingScreen.runAnimation();
                    window.draw(endingScreen.getSprite());
                    window.display();
                }
                window.close();
            }
        }
        if (jumpscare==true)
        {
            static bool soundPlayed = false;
            if (!soundPlayed) {
                scareOne.playSound();
                fan.stopSound();
                music.stop();
                call.stop();
                soundPlayed = true;
            }
            bonnieScare.runAnimation();
            window.draw(bonnieScare.getSprite());
            if (soundPlayed && scareOne.getStatus() == true) {
                window.close();
            }
        }
        if (call.getStatus()==sf::Music::Stopped && !ambiencePlaying)
        {
            music.play();
            ambiencePlaying=true;
        }
        //window.draw(button);
        //window.draw(text);
        window.display();
    }
    return 0;

}