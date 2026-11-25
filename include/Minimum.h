#ifndef MINIMUM_H
#define MINIMUM_H

#include "Function.h"

    class Minimum {
        public:
            // Funzione per calcolare il minimo di una funzione matematica a 2 variabili
            static void calculateMin(const Function& f, float x0, float y0, float t);
            // Funzione per calcolare la norma del gradiente
            static float calculateGradNorm(float dx, float dy);

    };

#endif
