#ifndef IOMINIMUM_H
#define IOMINIMUM_H

#include "Function.h"

class IOminimum {
public:
  static int selectFunction();
  static Function getFunction(int choice);
  static float selectCoordinate(std::string nameOfCoordinate);
};

#endif // IOMINIMUM_H
