#include "IOminimum.h"
#include <iostream>

int IOminimum::selectFunction() {
    int choice;
    std::cout << "Select a function to execute:" << std::endl;
    std::cout << "1. Function A" << std::endl;
    std::cout << "2. Function B" << std::endl;
    std::cout << "3. Function C" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    return choice;
}