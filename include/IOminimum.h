#ifndef IOMINIMUM_H
#define IOMINIMUM_H

#include "Function.h"

class IOminimum {
    public:
        // Funzione per selezionare una funzione matematica da un elenco
        static int selectFunction();
        // Funzione per ottenere un oggetto Function in base alla scelta dell'utente
        static Function getFunction(int choice);
        // Funzione per selezionare una coordinata (x o y)
        static float selectCoordinate(std::string nameOfCoordinate);
        // Funzione per ottenere il target (la soglia di convergenza)
        static float getT();
};

#endif
