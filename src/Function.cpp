#include "../include/Function.h"
#include <stdexcept>

  Function::Function(){}

  // Costruttore parametrico
  Function::Function(const int id,
                      const std::string& testo,
                      MathFunc2D f,
                      MathFunc2D grad_x,
                      MathFunc2D grad_y,
                      float valore_minimo)
                      : 
                      id(id),
                      testo(testo),
                      f(f), 
                      grad_x(grad_x), 
                      grad_y(grad_y), 
                      valore_minimo(valore_minimo) {}

  // Costruttore di copia
  Function::Function(const Function &other)
                    : 
                    id(other.id), 
                    testo(other.testo),
                    f(other.f),
                    grad_x(other.grad_x),
                    grad_y(other.grad_y),
                    valore_minimo(other.valore_minimo) {}

  // Distruttore
  Function::~Function() {}

  // Calcola il valore della funzione 
  float Function::solve(float x, float y) const {
    if (f) {
      return f(x, y);
    }
    throw std::runtime_error("Funzione f(x, y) non impostata per " + id);
  }

  // Calcola il valore della derivata parziale rispetto a x
  float Function::solveGradX(float x, float y) const {
    if (grad_x) {
      return grad_x(x, y);
    }
    throw std::runtime_error("Derivata parziale df/dx non impostata per " + id);
  }

  // Calcola il valore della derivata parziale rispetto a y
  float Function::solveGradY(float x, float y) const {
    if (grad_y) {
      return grad_y(x, y);
    }
    throw std::runtime_error("Derivata parziale df/dy non impostata per " + id);
  }

  //getters
  int Function::getId() const {
    return id;
  }

  // Ritorna la rappresentazione testuale della funzione
  std::string Function::getFunzione() const {
    return testo;
  }


  // Getters per funzioni eseguibili
  MathFunc2D Function::getFunction() const {
    return f; // Ritorna la funzione f(x, y)
  }

  MathFunc2D Function::getGradX() const {
    return grad_x; // Ritorna la derivata parziale df/dx
  }

  MathFunc2D Function::getGradY() const {
    return grad_y; // Ritorna la derivata parziale df/dy
  }

  // Getter per il valore minimo atteso
  float Function::getValoreMinimo() const {
    return valore_minimo;
  }

  // Overload dell'operatore di output per stampare le informazioni della funzione
  std::ostream& operator<<(std::ostream& os, const Function& func){

    os << "Function [ID: " << func.getId() << "] " << "f(x, y) = " << func.getFunzione()<< " | Valore minimo: " << func.getValoreMinimo();

    return os;

  }