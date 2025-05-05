/**
* @file chrono.cpp
* @author Elaine Park
* @brief testing out the chrono library
* @date 2025-04-16
*/

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

class Enemy
{
public:
    void timer()
    {
        auto start = steady_clock::now();
        auto one_second = 1//s;
        ;
        for (int i = 0; i < mWait; i++)
        {
            std::this_thread::sleep_for(one_second);
            auto dur = steady_clock::now() - start;
            std::cout << duration_cast<seconds>(dur).count() << '\n';
        }
        std::cout << "Monster Moves\n";
    }
    int mWait;
};

int main ()
{
    Enemy monster;
    monster.mWait = 20;
    monster.timer();
    monster.mWait = 10;
    monster.timer();
    return 0;
}