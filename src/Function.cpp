#include "../include/Function.h"
#include <stdexcept>

// Costruttore di default
Function::Function()
    : nome(""), formula_testo(""), derivata_x_testo(""), derivata_y_testo(""),
      f(nullptr), grad_x(nullptr), grad_y(nullptr), minimo_x(0.0),
      minimo_y(0.0), valore_minimo(0.0) {}

// Costruttore parametrizzato completo
Function::Function(const std::string &nome, const std::string &formula_testo,
                   const std::string &derivata_x_testo,
                   const std::string &derivata_y_testo, MathFunc2D f,
                   MathFunc2D grad_x, MathFunc2D grad_y, double minimo_x,
                   double minimo_y, double valore_minimo)
    : nome(nome), formula_testo(formula_testo),
      derivata_x_testo(derivata_x_testo), derivata_y_testo(derivata_y_testo),
      f(f), grad_x(grad_x), grad_y(grad_y), minimo_x(minimo_x),
      minimo_y(minimo_y), valore_minimo(valore_minimo) {}

// Costruttore di copia
Function::Function(const Function &other)
    : nome(other.nome), formula_testo(other.formula_testo),
      derivata_x_testo(other.derivata_x_testo),
      derivata_y_testo(other.derivata_y_testo), f(other.f),
      grad_x(other.grad_x), grad_y(other.grad_y), minimo_x(other.minimo_x),
      minimo_y(other.minimo_y), valore_minimo(other.valore_minimo) {}

// Distruttore
Function::~Function() {}

// Valutazione numerica
double Function::eval(double x, double y) const {
  if (f) {
    return f(x, y);
  }
  throw std::runtime_error("Funzione f(x, y) non impostata per " + nome);
}

double Function::evalGradX(double x, double y) const {
  if (grad_x) {
    return grad_x(x, y);
  }
  throw std::runtime_error("Derivata parziale df/dx non impostata per " + nome);
}

double Function::evalGradY(double x, double y) const {
  if (grad_y) {
    return grad_y(x, y);
  }
  throw std::runtime_error("Derivata parziale df/dy non impostata per " + nome);
}

// Getters descrittivi
std::string Function::getNome() const { return nome; }

std::string Function::getId() const { return nome; }

std::string Function::getFunzione() const { return formula_testo; }

std::string Function::getDerivataX() const { return derivata_x_testo; }

std::string Function::getDerivataY() const { return derivata_y_testo; }

// Getters per funzioni eseguibili
MathFunc2D Function::getCallableFunction() const { return f; }

MathFunc2D Function::getCallableGradX() const { return grad_x; }

MathFunc2D Function::getCallableGradY() const { return grad_y; }

// Getters per il minimo atteso
double Function::getMinimoX() const { return minimo_x; }

double Function::getMinimoY() const { return minimo_y; }

double Function::getValoreMinimo() const { return valore_minimo; }

// Setters
void Function::setNome(const std::string &nome) { this->nome = nome; }

void Function::setFunzione(const std::string &formula_testo) {
  this->formula_testo = formula_testo;
}

void Function::setDerivataX(const std::string &derivata_x_testo) {
  this->derivata_x_testo = derivata_x_testo;
}

void Function::setDerivataY(const std::string &derivata_y_testo) {
  this->derivata_y_testo = derivata_y_testo;
}

void Function::setCallableFunction(MathFunc2D f) { this->f = f; }

void Function::setCallableGradX(MathFunc2D grad_x) { this->grad_x = grad_x; }

void Function::setCallableGradY(MathFunc2D grad_y) { this->grad_y = grad_y; }

void Function::setMinimoX(double minimo_x) { this->minimo_x = minimo_x; }

void Function::setMinimoY(double minimo_y) { this->minimo_y = minimo_y; }

void Function::setValoreMinimo(double valore_minimo) {
  this->valore_minimo = valore_minimo;
}
