#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "animatronic.h"
#include "sounds.h"
#include "room.h"
#include "button.h"

int main()
{
    std::srand(std::time(NULL));

    int power=999;
    //Animatronic freddy(1);
    //Animatronic bonnie(3);
    //Animatronic chica(3);
    //Animatronic foxy(2);

    bool gameOver=false;
    
    

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
   

    cameraButtons.push_back(Button ("", sf::Vector2f(1296, 357), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1276, 413), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1170, 440), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1244, 491), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1212, 589), sf::Vector2f(53, 32), sf::Color::Transparent));

    cameraButtons.push_back(Button ("", sf::Vector2f(1296, 607), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1296, 647), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1508, 441), sf::Vector2f(53, 32), sf::Color::Transparent));
    //kitchen stuff
    cameraButtons.push_back(Button ("", sf::Vector2f(1402, 608), sf::Vector2f(53, 32), sf::Color::Transparent));
    cameraButtons.push_back(Button ("", sf::Vector2f(1402, 648), sf::Vector2f(53, 32), sf::Color::Transparent));

    bool cameraOpen=true;
    bool mouseInButton;
    int currentRoom=0;

   
    sf::RenderWindow window(sf::VideoMode(800, 500), "MyButton!");
    sf::Texture texture;
    if (!texture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    
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
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            //get position of the mouse
            //sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2i mPos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);
            bool mouseInButton =    mousePosition.x >= button.getPosition().x - button.getGlobalBounds().width/2
                                    && mousePosition.x <= button.getPosition().x + button.getGlobalBounds().width/2
                                    && mousePosition.y >= button.getPosition().y - button.getGlobalBounds().height/2
                                    && mousePosition.y <= button.getPosition().y + button.getGlobalBounds().height/2;
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
        }


        sf::Vector2i mPos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mPos);

        for(int i=0; i<10; i++)
        {
            if(event.type==sf::Event::MouseButtonPressed) {
                mouseInButton =    mousePosition.x >= cameraButtons[i].getPosition().x - cameraButtons[i].getDimensions().x
                && mousePosition.x <= cameraButtons[i].getPosition().x + cameraButtons[i].getDimensions().x
                && mousePosition.y >= cameraButtons[i].getPosition().y - cameraButtons[i].getDimensions().y
                && mousePosition.y <= cameraButtons[i].getPosition().y + cameraButtons[i].getDimensions().y;
            
                if(mouseInButton) {
                    currentRoom=i;
                }
            }
        }

        window.clear();


        
        
        if(cameraOpen) {
            window.draw(allRooms[currentRoom].getRoomPicture());
            window.draw(cameraMenu);
            for(int i=0; i<10; i++)
            {
                window.draw(cameraButtons[i]);
            }
        }
        window.draw(button);
        window.draw(text);
        window.display();
    }
    Sound sound;
    sound.loadSound("pigeons-flying-6351.mp3");
    sound.playSound();
    return 0;

}