#include "vetor.h"
#include <iostream>

Vetor::Vetor(int inicio, int fim) : inicio_(inicio){
    if(fim>=inicio){
        elementos_ = new string[fim - inicio +1];
    }
    else{
        throw "Tamanho de fim maior que inicio";
    }
}

void Vetor::atribuir(int i, std::string valor){
    int j = i - inicio_;
    elementos_[j] = valor;
}  

string Vetor::valor(int i) const{
    int j = i- inicio_;
    return elementos_[j];
}

Vetor::~Vetor(){
    delete[] elementos_;
}