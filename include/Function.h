#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <functional>
#include <iostream>

// Tipo per funzioni matematiche a 2 variabili f(x, y)
using MathFunc2D = std::function<float(float, float)>;

class Function {

    public:
        //costruttori
        Function();
        Function(const int id,
             const std::string& testo,
             MathFunc2D f,
             MathFunc2D grad_x,
             MathFunc2D grad_y,
             float valore_minimo);

        Function(const Function& other); // Costruttore di copia

        ~Function(); // Distruttore

        // calcola la funzione (funzione, gradiente x, gradiente y)
        float solve(float x, float y) const;
        float solveGradX(float x, float y) const;
        float solveGradY(float x, float y) const;

        // Getters (id e testo della funzione)
        int getId() const;
        std::string getFunzione() const;

        // Getters per le funzioni eseguibili
        MathFunc2D getFunction() const;
        MathFunc2D getGradX() const;
        MathFunc2D getGradY() const;

        // Getters per il minimo atteso
        float getValoreMinimo() const;

        
    private:
        
        int id{0};
        std::string testo {"y = f(x)"};
        MathFunc2D f{nullptr};
        MathFunc2D grad_x{nullptr};
        MathFunc2D grad_y{nullptr};
        float valore_minimo {0.0f};
        
    };
    
    // Overload dell'operatore di output per stampare le informazioni della funzione
    std::ostream& operator<<(std::ostream& os, const Function& func); 

#endif