#include "../include/IOminimum.h"
#include <iostream>

int main() {
  int choice = IOminimum::selectFunction();

  std::cout << "You selected function " << choice << "." << std::endl;

  Function f = IOminimum::getFunction(choice);

  std::cout << "Function " << f.getId() << ": " << f.getFunzione() << std::endl;

  return 0;
}