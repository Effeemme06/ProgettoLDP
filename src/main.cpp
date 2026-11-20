#include "../include/Function.h"
#include "../include/IOminimum.h"
#include <iostream>

int main() {

  int choice = IOminimum::selectFunction();
  std::cout << "\nHai scelto la funzione " << choice << "." << std::endl;

  Function f = IOminimum::getFunction(choice);
  std::cout << "\nDati della funzione: " << f << std::endl;

  float x_start = IOminimum::selectCoordinate("x");
  float y_start = IOminimum::selectCoordinate("y");

  std::cout << "Punto di partenza: (" << x_start << ", " << y_start << ")\n" << std::endl;
  std::cout << f.solve(x_start, y_start) << std::endl;
  std::cout << f.solveGradX(x_start, y_start) << std::endl;
  std::cout << f.solveGradY(x_start, y_start) << std::endl;

  return 0;
}