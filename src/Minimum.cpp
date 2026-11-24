#include "../include/Minimum.h"
#include <cmath>
#include <iostream>

namespace {

    // Stampa periodica dei valori
    void printStatus(int k, float x, float y, float fValue, float error, float gradNorm){
        std::cout << "\nk: " << k << "; p: ("<< x <<", " << y <<")" << "; f(p): " << fValue << "; Error: " << error<< "; ||∇f(p)||: " << gradNorm << std::endl;
    }

    // Stampa i risulatati finali dopo la discesa del gradiente, punto finale
    void printFinalOutput(bool ended, int totalIterations, float x, float y, float finalF, float finalError, float finalGradNorm, float t, int n){
        std::cout << "\nPosizione finale del punto p: ("<< x <<", " << y <<")" << std::endl;
        std::cout << "Valore della funzione in f(p):  "<< finalF << std::endl;
        std::cout << "Errore finale: "<< finalError << std::endl;
        std::cout << "Norma gradiente finale: "<< finalGradNorm << std::endl;
        std::cout << "Iterazioni eseguite: "<< totalIterations << std::endl;
        if (ended) {
            std::cout << "E' stata superata la soglia T: ||∇f(p)|| < T (" << finalGradNorm << " < " << t << ")" << std::endl;
        } else {
            std::cout << "E' stato raggiunto il limite massimo di iterazioni N = " << n << std::endl;
        }
    }
    
    // Usa Armijo Backtracking per calcolare a in modo variabile
    float calculateA(const Function& f, float fValue, float a, float x, float y, float gradNorm, float dx, float dy){
        const float c = 1e-4f;   // Costante di Armijo
        const float beta = 0.5f; // Fattore di riduzione del passo
        float currentA = a;
        bool valid = false;

        while(currentA > 1e-7f && !valid){ //Soglia per non avere un a troppo piccolo
            float nextX = x - currentA*dx;
            float nextY = y - currentA*dy;
            // Calcola il possibile passo successivo
            float nextF = f.solve(nextX, nextY); 

            // Verifica se per la formula di Armijo il passo è accettabile
            if (nextF <= fValue - c*currentA*(gradNorm*gradNorm)) {
                valid = true;
            }else{
                currentA *= beta; 
                valid = false;
            }
           
        }
        return currentA; // Restituisce a aggiornato
    }

}



// Calcola il minimo della funzione usando il cammino del gradiente
void Minimum::calculateMin(const Function& f, float x0, float y0, float t){
    float a=0.1f;    // Passo a
    int n = 1000;    // Soglia iterazioni
    
    float fMin = f.getValoreMinimo(); 
    float x = x0, y = y0;

    int totalIterations = 0;
    bool ended = false;
    float fValue = 0.0f;
    float error = 0.0f;
    float gradNorm = 0.0f;

    for(int k=0; k<=n && !ended; k++){

        totalIterations = k;
        float currentA = a;

        // Cacolo del valore della funzione, errore, derivate parziali
        fValue = f.solve(x, y);

        error = fValue - fMin;

        float dx = f.solveGradX(x, y);
        float dy = f.solveGradY(x, y);
        
        gradNorm = calculateGradNorm(dx, dy);

        // Output periodico da stampare all'utente
        if(k%10 == 0){
            printStatus(k, x, y, fValue, error, gradNorm);
        }

        // Verifica della soglia T
        if(gradNorm < t){
            ended = true;
        }

        if(!ended){
            currentA = calculateA(f, fValue, currentA, x, y, gradNorm, dx, dy);

            // Compie il passo utilizzando a aggiornata
            x = x - currentA*dx;
            y = y - currentA*dy;
        }
    }

    printFinalOutput(ended, totalIterations, x, y, fValue, error, gradNorm, t, n);
}

float Minimum::calculateGradNorm(float dx, float dy){
    return std::sqrt(dx*dx + dy*dy);
}
