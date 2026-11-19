#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <functional>

// Tipo per funzioni matematiche a 2 variabili f(x, y)
using MathFunc2D = std::function<double(double, double)>;

class Function {
private:
    std::string nome;
    std::string formula_testo;
    std::string derivata_x_testo;
    std::string derivata_y_testo;
    MathFunc2D f;
    MathFunc2D grad_x;
    MathFunc2D grad_y;
    double minimo_x;
    double minimo_y;
    double valore_minimo;

public:
    // Costruttore di default
    Function();

    // Costruttore parametrizzato completo con funzioni matematiche eseguibili (lambda)
    Function(const std::string& nome,
             const std::string& formula_testo,
             const std::string& derivata_x_testo,
             const std::string& derivata_y_testo,
             MathFunc2D f,
             MathFunc2D grad_x,
             MathFunc2D grad_y,
             double minimo_x,
             double minimo_y,
             double valore_minimo);

    // Costruttore di copia
    Function(const Function& other);

    // Distruttore
    virtual ~Function();

    // Valutazione numerica della funzione e delle derivate
    double eval(double x, double y) const;
    double evalGradX(double x, double y) const;
    double evalGradY(double x, double y) const;

    // Getters descrittivi
    std::string getNome() const;
    std::string getId() const; // Alias per getNome()
    std::string getFunzione() const;
    std::string getDerivataX() const;
    std::string getDerivataY() const;

    // Getters per le funzioni eseguibili
    MathFunc2D getCallableFunction() const;
    MathFunc2D getCallableGradX() const;
    MathFunc2D getCallableGradY() const;

    // Getters per il minimo atteso
    double getMinimoX() const;
    double getMinimoY() const;
    double getValoreMinimo() const;

    // Setters
    void setNome(const std::string& nome);
    void setFunzione(const std::string& formula_testo);
    void setDerivataX(const std::string& derivata_x_testo);
    void setDerivataY(const std::string& derivata_y_testo);
    void setCallableFunction(MathFunc2D f);
    void setCallableGradX(MathFunc2D grad_x);
    void setCallableGradY(MathFunc2D grad_y);
    void setMinimoX(double minimo_x);
    void setMinimoY(double minimo_y);
    void setValoreMinimo(double valore_minimo);
};

#endif // FUNCTION_H
