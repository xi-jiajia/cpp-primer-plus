#include <iostream>
#include <cstring>
#include "Cow.h"

int main()
{
    std::cout << "Initialize, and show No.1: " << std::endl;
    Cow cow_list[2] = { {"Tom", "Sleepy", 200} };
    cow_list[0].ShowCow();
    std::cout << std::endl;

    std::cout << "No.2's default values: " << std::endl;
    cow_list[1].ShowCow();
    std::cout << std::endl;

    std::cout << "Now using operator=() to init No.2." << std::endl;
    cow_list[1] = cow_list[0];
    cow_list[1].ShowCow();
    std::cout << std::endl;

    std::cout << "Now, using copy constructor to init No.3." << std::endl;
    Cow copy(cow_list[0]);
    copy.ShowCow();
    std::cout << std::endl;
}