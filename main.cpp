#include <iostream>

int addThree(int initial);

int main()
{
    std::cout << "Hello, World!\n";
    std::cout << "Type a number: ";
    int num;
    std::cin >> num;
    std::cout << num << " + 3 = " << addThree(num) << '\n';
    return 0;
}

int addThree(int initial)
{
    int result = initial + 3;
    return result;
}