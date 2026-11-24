#ifndef MINIMUM_H
#define MINIMUM_H

#include "Function.h"

    class Minimum {
        public:
            static void calculate(const Function& f, float x0, float y0);
            static void calculateMin(const Function& f, float x0, float y0, float t);
            static float calculateGradNorm(float dx, float dy);

    };

#endif
