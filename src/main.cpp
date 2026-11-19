#include <iostream>
#include "IOminimum.h"

int main() {
    IOminimum io;
    int choice = io.selectFunction();

    std::cout << "You selected function " << choice << "." << std::endl;
    return 0;
}