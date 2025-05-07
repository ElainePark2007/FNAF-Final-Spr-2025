# Final Project: Five Nights at Freddy's
Try your luck surviving the night shift at Freddy Fazbear's Pizzeria with this project. Monitor the roaming animatronics by pressing 'C'. Checking the cameras when they're right outside scares them off, but don't lose them in the rooms, or else!

![FNAFex1](https://github.com/user-attachments/assets/623dcd3c-8f4e-49e2-a9d9-1ff3667a6f4c)
![FNAFex2](https://github.com/user-attachments/assets/8e03d4e1-681a-44d4-9b67-9286c5d7cb1d)
![FNAFex3](https://github.com/user-attachments/assets/df770e50-b0b5-49b2-8f05-456be5c160de)

## Installation
Clone the repository onto your device using Ubuntu

WARNING: This game takes a large amount of processing power and likely won't work for underpowered or older computers or laptops

## Compiler Code:
Windows:
```bash
g++ -std=c++11 *.cpp -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
```
Mac:
```bash
g++ -std=c++11 *.cpp -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -I/usr/local/opt/sfml@2/include -L/usr/local/opt/sfml@2/lib
```
