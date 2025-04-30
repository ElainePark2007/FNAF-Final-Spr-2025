#include <SFML/Graphics.hpp>
#include <iostream>
#include "animatronic.h"

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
    
   

    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //Main Game Loop
        // while(!gameOver)
        // {
        //      /*Create timer that removes a power every 6 seconds (passive power drain that starts on night 2, 
        //     but since we are only doing one night, we can just have it on the first night))*/

        //     /*Every five seconds, call *insert animatronic name*.movementOpportunity(*animatronic name*.getAiLevel()*/
        // }

        window.clear();
        window.display();

    }



    
    return 0;
}