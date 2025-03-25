#include <iostream>

int addThree(int initial);

void printName()
{
    std::cout<<"My name is Matteo\n";
}


int main()
{
    std::cout << "Hello, World!\n";

    std::cout << "Type a number: ";
    int num;
    std::cin >> num;
    std::cout << num << " + 3 = " << addThree(num) << '\n';
    printName();

    std::cout<<"I am Luke\n";
    return 0;
    return 0;
}

int addThree(int initial)
{
    int result = initial + 3;
    return result;
}