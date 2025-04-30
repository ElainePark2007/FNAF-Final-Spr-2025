#include <SFML/Graphics.hpp>
#include <iostream>
#include "animatronic.h"
#include "sounds.h"

int main()
{
    std::srand(std::time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    int power=999;
    Animatronic freddy(1);
    Animatronic bonnie(3);
    Animatronic chica(3);
    Animatronic foxy(2);

    bool gameOver=false;
    
   
    sf::RenderWindow window(sf::VideoMode(800, 500), "MyButton!");
    sf::Texture texture;
    if (!texture.loadFromFile("button.png"))
    {
        std::cout<<"Error opening file\n";
        exit(1);
    }
    std::string l = "pigeons-flying-6351.mp3";
    sf::SoundBuffer buffer;
                if (!buffer.loadFromFile(l))
                    {return -1;}
                sf::Sound sound(buffer);
    
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
                        sound.play();
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
        window.clear();
        window.draw(button);
        window.draw(text);
        window.display();
    }
    return 0;



    
    return 0;
}