#include "../include/IOminimum.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace {
// Registro interno in-memory contenente tutte le 8 funzioni con le rispettive
// formule ed espressioni lambda eseguibili
const std::map<int, Function> &getFunctionRegistry() {
  static const std::map<int, Function> registry = {
      {1, Function(
              "f1", "(pow(x, 2) + pow(y, 2)) / 2.0", "x", "y",
              [](double x, double y) { return (x * x + y * y) / 2.0; },
              [](double x, double) { return x; },
              [](double, double y) { return y; }, 0.0, 0.0, 0.0)},
      {2, Function(
              "f2", "(pow(x, 2) + 16.0 * pow(y, 2)) / 2.0", "x", "16.0 * y",
              [](double x, double y) { return (x * x + 16.0 * y * y) / 2.0; },
              [](double x, double) { return x; },
              [](double, double y) { return 16.0 * y; }, 0.0, 0.0, 0.0)},
      {3, Function(
              "f3", "pow(pow(x, 2) - 1.0, 2) + pow(y, 2)",
              "4.0 * x * (pow(x, 2) - 1.0)", "2.0 * y",
              [](double x, double y) {
                double t = x * x - 1.0;
                return t * t + y * y;
              },
              [](double x, double) { return 4.0 * x * (x * x - 1.0); },
              [](double, double y) { return 2.0 * y; }, 1.0, 0.0, 0.0)},
      {4,
       Function(
           "f4", "pow(pow(x, 2) - 1.0, 2) + pow(x - 1.0, 2) / 5.0 + pow(y, 2)",
           "4.0 * x * (pow(x, 2) - 1.0) + (2.0 / 5.0) * (x - 1.0)", "2.0 * y",
           [](double x, double y) {
             double t = x * x - 1.0;
             return t * t + (x - 1.0) * (x - 1.0) / 5.0 + y * y;
           },
           [](double x, double) {
             return 4.0 * x * (x * x - 1.0) + (2.0 / 5.0) * (x - 1.0);
           },
           [](double, double y) { return 2.0 * y; }, 1.0, 0.0, 0.0)},
      {5, Function(
              "f5", "4.0 * pow(sinh(x / 2.0), 2) + pow(y, 2)",
              "4.0 * sinh(x / 2.0) * cosh(x / 2.0)", "2.0 * y",
              [](double x, double y) {
                double s = std::sinh(x / 2.0);
                return 4.0 * s * s + y * y;
              },
              [](double x, double) {
                return 4.0 * std::sinh(x / 2.0) * std::cosh(x / 2.0);
              },
              [](double, double y) { return 2.0 * y; }, 0.0, 0.0, 0.0)},
      {6,
       Function(
           "f6", "log(1.0 + pow(x, 2) + pow(y, 2))",
           "(2.0 * x) / (1.0 + pow(x, 2) + pow(y, 2))",
           "(2.0 * y) / (1.0 + pow(x, 2) + pow(y, 2))",
           [](double x, double y) { return std::log(1.0 + x * x + y * y); },
           [](double x, double y) { return (2.0 * x) / (1.0 + x * x + y * y); },
           [](double x, double y) { return (2.0 * y) / (1.0 + x * x + y * y); },
           0.0, 0.0, 0.0)},
      {7,
       Function(
           "f7", "1.0 - exp(-(pow(x, 2) + pow(y, 2)))",
           "2.0 * x * exp(-(pow(x, 2) + pow(y, 2)))",
           "2.0 * y * exp(-(pow(x, 2) + pow(y, 2)))",
           [](double x, double y) { return 1.0 - std::exp(-(x * x + y * y)); },
           [](double x, double y) {
             return 2.0 * x * std::exp(-(x * x + y * y));
           },
           [](double x, double y) {
             return 2.0 * y * std::exp(-(x * x + y * y));
           },
           0.0, 0.0, 0.0)},
      {8, Function(
              "f8", "2.0 - cos(M_PI * x) - cos(M_PI * y)",
              "M_PI * sin(M_PI * x)", "M_PI * sin(M_PI * y)",
              [](double x, double y) {
                return 2.0 - std::cos(M_PI * x) - std::cos(M_PI * y);
              },
              [](double x, double) { return M_PI * std::sin(M_PI * x); },
              [](double, double y) { return M_PI * std::sin(M_PI * y); }, 0.0,
              0.0, 0.0)}};
  return registry;
}
} // namespace

int IOminimum::selectFunction() {
  int choice = 0;
  while (choice < 1 || choice > 8) {
    std::cout << "Invalid choice. Please select a number between 1 and 8."
              << std::endl;
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
    } catch (const std::invalid_argument &e) {
      std::cout << "Error: " << e.what() << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      choice = 0;
    }
  }

  return choice;
}

Function IOminimum::getFunction(int choice) {
  const auto &registry = getFunctionRegistry();
  auto it = registry.find(choice);
  if (it != registry.end()) {
    return it->second;
  }
  throw std::out_of_range("La scelta deve essere compresa tra 1 e 8.");
}
