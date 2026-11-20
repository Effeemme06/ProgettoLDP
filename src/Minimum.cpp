#include "../include/Minimum.h"
#include <cmath>
#include <iostream>
#include <iomanip>

namespace {
    // k     p_k     f(p_k)     e_k = f(p_k) - m     ||∇f(p_k)||
    void printIteration(int k, float x, float y, float f_val, float error, float grad_norm) {

        std::cout << "\nk: " << k
                  << " | p_k: (" << x << ", " << y << ")"
                  << " | f(p_k): " << f_val
                  << " | e_k: " << error
                  << " | ||∇f(p_k)||: " << grad_norm
                  << std::endl;

    }

}

void Minimum::calculate(const Function& f, float x0, float y0){

    float a = 0.1f;
    float T = 1e-4f;
    int N = 1000;

    float x = x0;
    float y = y0;
    float m = f.getValoreMinimo(); // Minimo della funzione noto a priori

    std::cout << "\n================== Discesa del Gradiente ==================" << std::endl;
    std::cout << "Funzione [ID " << f.getId() << "]: " << f.getFunzione() << std::endl;
    std::cout << "Posizione iniziale p_0 = (" << x0 << ", " << y0 << ")" << std::endl;
    std::cout << "Passo iniziale a: " << a << " (passo variabile con backtracking)" << std::endl;
    std::cout << "Soglia tolleranza T: " << T << " | Max iterazioni N: " << N << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    int lastPrintedK = -1;
    int totalIterations = 0;
    bool converged = false;
    float finalF = 0.0f;
    float finalError = 0.0f;
    float finalGradNorm = 0.0f;

    for (int k = 0; k <= N; ++k) {
        totalIterations = k;

        // Calcolo valore f(p_k)
        float f_k = f.solve(x, y);

        // Calcolo errore e_k = f(p_k) - m
        float e_k = f_k - m;

        // Calcolo derivate parziali: fx e fy
        float gx = f.solveGradX(x, y);
        float gy = f.solveGradY(x, y);

        // Norma del gradiente: ||∇f(p_k)|| = sqrt(fx^2 + fy^2)
        float gradNorm = std::sqrt(gx * gx + gy * gy);

        finalF = f_k;
        finalError = e_k;
        finalGradNorm = gradNorm;

        // Output all'utente: ogni 10 iterazioni (k = 0, 10, 20, ...)
        if (k % 10 == 0) {
            printIteration(k, x, y, f_k, e_k, gradNorm);
            lastPrintedK = k;
        }

        // Criterio di arresto 1: la norma del gradiente e' inferiore alla soglia T
        if (gradNorm < T) {
            converged = true;
            if (lastPrintedK != k) {
                printIteration(k, x, y, f_k, e_k, gradNorm);
                lastPrintedK = k;
            }
            break;
        }

        // Criterio di arresto 2: raggiunto numero massimo di iterazioni N
        if (k == N) {
            if (lastPrintedK != k) {
                printIteration(k, x, y, f_k, e_k, gradNorm);
                lastPrintedK = k;
            }
            break;
        }

        // Spostamento verso il passo successivo con passo 'a' variabile (Armijo Backtracking)
        float currentA = a;
        const float c = 1e-4f;
        const float beta = 0.5f;
        float normSq = gradNorm * gradNorm;

        while (currentA > 1e-7f) {
            float nextX = x - currentA * gx;
            float nextY = y - currentA * gy;
            float nextF = f.solve(nextX, nextY);

            if (nextF <= f_k - c * currentA * normSq) {
                break;
            }
            currentA *= beta;
        }

        x = x - currentA * gx;
        y = y - currentA * gy;
    }

    // Output finale richiesto dalle specifiche:
    // Stampa la posizione finale del punto p_E ed il corrispondente valore f(p_E)
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Posizione finale del punto p_E: (" << std::fixed << std::setprecision(6) << x << ", " << y << ")" << std::endl;
    std::cout << "Valore della funzione f(p_E):  " << std::setprecision(6) << finalF << std::endl;
    std::cout << "Errore finale e_E:             " << std::setprecision(6) << finalError << std::endl;
    std::cout << "Norma gradiente finale:        " << std::setprecision(6) << finalGradNorm << std::endl;
    std::cout << "Iterazioni eseguite:           " << totalIterations << std::endl;
    if (converged) {
        std::cout << "Criterio di arresto: ||∇f(p_E)|| < T (" << finalGradNorm << " < " << T << ")" << std::endl;
    } else {
        std::cout << "Criterio di arresto: Raggiunto limite massimo di iterazioni N = " << N << std::endl;
    }
    std::cout << "============================================================\n" << std::endl;

}