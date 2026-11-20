#include "../include/IOminimum.h"
#include "../include/Function.h"
#include <iostream>

int main() {

  int choice = IOminimum::selectFunction();
  std::cout << "Hai scelto la funzione " << choice << "." << std::endl;

  Function f = IOminimum::getFunction(choice);
  //std::cout << "Dati della funzione: " << f;

  return 0;
}