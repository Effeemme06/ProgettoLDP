#include "include/IOminimum.h"
#include <iostream>

int IOminimum::selectFunction() {
    
    int choice = 0;
    while (choice < 1 || choice > 8) {
        std::cout << "Invalid choice. Please select a number between 1 and 8." << std::endl;
        std::cout << "Select a function to execute:" << std::endl;
        std::cout << "1. f1(x, y) = (x^2 + y^2) / 2" << std::endl;
        std::cout << "2. f2(x, y) = (x^2 + 16y^2) / 2" << std::endl;
        std::cout << "3. f3(x, y) = (x^2 - 1)^2 + y^2" << std::endl;
        std::cout << "4. f4(x, y) = (x^2 - 1)^2 + (x - 1)^2 / 5 + y^2" << std::endl;
        std::cout << "5. f5(x, y) = 4sinh^2(x / 2) + y^2" << std::endl;
        std::cout << "6. f6(x, y) = ln(1 + x^2 + y^2)" << std::endl;
        std::cout << "7. f7(x, y) = 1 - e^(-(x^2 + y^2))" << std::endl;
        std::cout << "8. f8(x, y) = 2 - cos(pi * x) - cos(pi * y)" << std::endl;
        std::cout << "Enter your choice (1-8): ";
        try {
            std::cin >> choice;
            if (std::cin.fail()) {
                throw std::invalid_argument("L'input deve essere un numero intero.");
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            choice = 0;
        }
    }

    return choice;
}