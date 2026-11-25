#include "../include/Function.h"
#include "../include/IOminimum.h"
#include "../include/Minimum.h"
#include <iostream>

int main() {

  // Selezione della funzione matematica da parte dell'utente
  int choice = IOminimum::selectFunction();
  std::cout << "\nHai scelto la funzione " << choice << "." << std::endl;

  // Ottenimento dell'oggetto Function corrispondente alla scelta dell'utente
  Function f = IOminimum::getFunction(choice);
  std::cout << "\nDati della funzione: " << f << std::endl;

  // Selezione delle coordinate iniziali (x, y) da parte dell'utente
  float x = IOminimum::selectCoordinate("x");
  float y = IOminimum::selectCoordinate("y");

  // Ottenimento del target (soglia di convergenza) da parte dell'utente
  float t = IOminimum::getT();

  // Stampa delle informazioni iniziali
  std::cout << "Punto di partenza: (" << x << ", " << y << ")\n" << std::endl;
  std::cout << "Valore della funzione nel punto di Partenza: " << f.solve(x, y) << std::endl;
  std::cout << "Valore della derivata parziale rispetto a x nel punto di Partenza: " << f.solveGradX(x, y) << std::endl;
  std::cout << "Valore della derivata parziale rispetto a y nel punto di Partenza: " << f.solveGradY(x, y) << std::endl;

  std::cout << "\nCalcolo del minimo della funzione attraverso il cammino del gradiente:" << std::endl;

  // Calcolo del minimo della funzione attraverso il cammino del gradiente
  Minimum::calculateMin(f, x, y, t);

  return 0;
  
}
