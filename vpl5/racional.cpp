#include "racional.h"


Racional::Racional(){
    numerador_ = 0;
    denominador_ = 1;
}

Racional::Racional(int n){
    numerador_ =n;
    denominador_ =1;
}

Racional::Racional(int n, int d){
    if(d == 0){
        throw "erro, divisao por zero";
    }
    else{
        numerador_ = n;
        denominador_ = d;
    }
    Simplificar();
}

int Racional::numerador() const {
    return numerador_;
}

int Racional::denominador() const{
    return denominador_;
}

Racional Racional::simetrico() const{
    return Racional(-numerador(), denominador());
}

Racional Racional::somar(Racional k) const{
    int den;
    int num;
    den = denominador()*k.denominador();
    num = (den/ denominador() * numerador()) + (den/ k.denominador() * k.numerador());
    return Racional(num, den);
}


Racional Racional::subtrair(Racional k) const{
    int den;
    int num;
    den = denominador()*k.denominador();
    num = (den/ denominador() * numerador()) - (den/ k.denominador() * k.numerador());
    return Racional(num, den);
}

Racional Racional::multiplicar(Racional k) const{
    int den = denominador()*k.denominador();
    int num = numerador()*k.numerador();
    return Racional(num,den);
}

Racional Racional::dividir(Racional k) const{
    return this->multiplicar(Racional(k.denominador(), k.numerador()));
}

int MaximoDivisorComum(int x, int y){
    x= abs(x);
    while(y>0){
        int aux = y;
        y= x%y;
        x = aux;
    }
    return x;
}


void Racional::Simplificar(){
    if(denominador_<0){
        numerador_ = -(numerador_);
        denominador_ = -(denominador_);
    }
    int mdc = MaximoDivisorComum(numerador_, denominador_);
    numerador_ = numerador_/mdc;
    denominador_ = denominador_/mdc;
}

//somar diferente do gabarito