#include "../include/IOminimum.h"
#include "../include/Function.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace {

// Registro interno contenente tutte le 8 funzioni con le formule ed espressioni
// eseguibili
const std::map<int, Function> &getFunctionRegistry() {

  static const std::map<int, Function> registry = {

      {1, Function(
              1, "(pow(x, 2) + pow(y, 2)) / 2.0",
              [](float x, float y) { return (x * x + y * y) / 2.0f; },
              [](float x, float) { return x; },
              [](float, float y) { return y; }, 0.0f)},

      {2, Function(
              2, "(pow(x, 2) + 16.0 * pow(y, 2)) / 2.0",
              [](float x, float y) { return (x * x + 16.0f * y * y) / 2.0f; },
              [](float x, float) { return x; },
              [](float, float y) { return 16.0f * y; }, 0.0f)},

      {3, Function(
              3, "pow(pow(x, 2) - 1.0, 2) + pow(y, 2)",
              [](float x, float y) {
                float t = x * x - 1.0f;
                return t * t + y * y;
              },
              [](float x, float) { return 4.0f * x * (x * x - 1.0f); },
              [](float, float y) { return 2.0f * y; }, 0.0f)},

      {4, Function(
              4, "pow(pow(x, 2) - 1.0, 2) + pow(x - 1.0, 2) / 5.0 + pow(y, 2)",
              [](float x, float y) {
                float t = x * x - 1.0f;
                return t * t + (x - 1.0f) * (x - 1.0f) / 5.0f + y * y;
              },
              [](float x, float) {
                return 4.0f * x * (x * x - 1.0f) + (2.0f / 5.0f) * (x - 1.0f);
              },
              [](float, float y) { return 2.0f * y; }, 0.0f)},

      {5, Function(
              5, "4.0 * pow(sinh(x / 2.0), 2) + pow(y, 2)",
              [](float x, float y) {
                float s = std::sinh(x / 2.0f);
                return 4.0f * s * s + y * y;
              },
              [](float x, float) {
                return 4.0f * std::sinh(x / 2.0f) * std::cosh(x / 2.0f);
              },
              [](float, float y) { return 2.0f * y; }, 0.0f)},

      {6,
       Function(
           6, "log(1.0 + pow(x, 2) + pow(y, 2))",
           [](float x, float y) { return std::log(1.0f + x * x + y * y); },
           [](float x, float y) { return (2.0f * x) / (1.0f + x * x + y * y); },
           [](float x, float y) { return (2.0f * y) / (1.0f + x * x + y * y); },
           0.0f)},

      {7,
       Function(
           7, "1.0 - exp(-(pow(x, 2) + pow(y, 2)))",
           [](float x, float y) { return 1.0f - std::exp(-(x * x + y * y)); },
           [](float x, float y) {
             return 2.0f * x * std::exp(-(x * x + y * y));
           },
           [](float x, float y) {
             return 2.0f * y * std::exp(-(x * x + y * y));
           },
           0.0f)},

      {8, Function(
              8, "2.0 - cos(M_PI * x) - cos(M_PI * y)",
              [](float x, float y) {
                return 2.0f - std::cos(static_cast<float>(M_PI) * x) -
                       std::cos(static_cast<float>(M_PI) * y);
              },
              [](float x, float) {
                return static_cast<float>(M_PI) *
                       std::sin(static_cast<float>(M_PI) * x);
              },
              [](float, float y) {
                return static_cast<float>(M_PI) *
                       std::sin(static_cast<float>(M_PI) * y);
              },
              0.0f)}};

  return registry;
}

} // namespace

int IOminimum::selectFunction() {

  int choice = 0;

  while (choice < 1 || choice > 8) {

    std::cout << "\nDigita un numero tra 1 e 8." << std::endl;
    std::cout << "\nSeleziona la funzione:" << std::endl;

    // aggiungere a questa lista le funzioni
    std::cout << "1. f1(x, y) = (x^2 + y^2) / 2" << std::endl;
    std::cout << "2. f2(x, y) = (x^2 + 16y^2) / 2" << std::endl;
    std::cout << "3. f3(x, y) = (x^2 - 1)^2 + y^2" << std::endl;
    std::cout << "4. f4(x, y) = (x^2 - 1)^2 + (x - 1)^2 / 5 + y^2" << std::endl;
    std::cout << "5. f5(x, y) = 4sinh^2(x / 2) + y^2" << std::endl;
    std::cout << "6. f6(x, y) = ln(1 + x^2 + y^2)" << std::endl;
    std::cout << "7. f7(x, y) = 1 - e^(-(x^2 + y^2))" << std::endl;
    std::cout << "8. f8(x, y) = 2 - cos(pi * x) - cos(pi * y)" << std::endl;
    std::cout << "Digita la tua scelta(1-8): ";

    try {

      std::cin >> choice;

      if (std::cin.fail()) {
        throw std::invalid_argument("L'input deve essere un numero intero.");
      }

    } catch (const std::invalid_argument &e) {

      std::cout << "Errore: " << e.what() << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      choice = 0;
    }
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
  return choice;

}

Function IOminimum::getFunction(int choice) {

  const auto &registro = getFunctionRegistry();
  auto funzione_caricata = registro.find(choice);

  if (funzione_caricata != registro.end()) {
    return funzione_caricata->second;
  }

  throw std::out_of_range("La scelta deve essere compresa tra 1 e 8.");
}


float IOminimum::selectCoordinate(std::string nameOfCoordinate) {

  float choice = -52.0f;

  while (choice < -50 || choice > 50) {

    std::cout << "\nDigita un numero tra -50 e 50." << std::endl;
    std::cout << "Digita il valore della coordinata " << nameOfCoordinate << " di partenza: ";

    try {

      std::cin >> choice;

      if (std::cin.fail()) {
        throw std::invalid_argument("L'input deve essere un numero.");
      }

    } catch (const std::invalid_argument &e) {

      std::cout << "Errore: " << e.what() << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      choice = -52.0f;
      
    }
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return choice;

}
