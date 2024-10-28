#include "racional.h"

#include <cmath>
#include <sstream>

Racional::Racional(){
    numerador_ = 0;
    denominador_ = 1;
}

Racional::Racional(int n){
    numerador_=n;
    denominador_=1;
}

Racional::Racional(int n, int d){
    if(d == 0){
        throw ExcecaoDivisaoPorZero{};
    }
    else{
    numerador_ = n;
    denominador_=d;
    Simplificar();}
}

int Racional::numerador() const{
    return numerador_;
}

int Racional::denominador() const{
    return denominador_;
}

Racional Racional::operator-() const{
    int aux = -numerador_;
    return Racional(aux, denominador_);
}

Racional Racional::operator+(Racional k) const{
    int den = mmc(this->denominador_, k.denominador_);
    int num = (den/this->denominador_ * this->numerador_) + (den/k.denominador_*k.numerador_);
    return Racional(num, den);
}

Racional Racional::operator*(Racional k) const{
    int num = this->numerador_ * k.denominador_;
    int den = this->denominador_ * k.denominador_;
    return Racional(num, den);
}

Racional Racional::operator/(Racional k) const{
    if(k.numerador_ == 0){
        throw ExcecaoDivisaoPorZero{};
    }
    int num = this->numerador_ * k.denominador_;
    int den = this->denominador_ * k.numerador_;
    return Racional(num, den);
}

Racional::operator float() const{
    float x = numerador_;
    return Racional(x,denominador_);
}

Racional::operator std::string() const{
    std::stringstream out;
    out<<numerador()<<"/"<<denominador();
    return out.str();
}

ostream& operator<<(ostream& out, Racional r){
    out<<r.numerador()<<'/'<<r.denominador();
    return out;
}

istream& operator>>(istream& in, Racional& r){
    int num, den;
    in>>num>>den;
    r = Racional(num, den);
    return in;
}

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular o MMC (Mínimo Múltiplo Comum)
int mmc(int a, int b) {
    return (a * b) / mdc(a, b);  // Fórmula do MMC
}

void Racional::Simplificar(){
    if (denominador_ <0){
        denominador_ = -denominador_;
        numerador_ = -numerador_;
    }
    int n = mdc(numerador_,denominador_);
    numerador_ = numerador_/n;
    denominador_ = denominador_/n;
}