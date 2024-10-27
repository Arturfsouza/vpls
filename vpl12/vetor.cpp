#include "vetor.h"

Vetor::Vetor(int inicio, int fim){
    if(fim<inicio){
        throw FimMenorQueInicio{inicio, fim};
    }
    inicio_ = inicio;
    fim_ = fim;
    elementos_ = new string[fim - inicio+1];
    inicializados_ = new bool[fim - inicio+1];
}

void Vetor::atribuir(int i, std::string valor){
    if(i<inicio_ || i>fim_){
        throw PosicaoInvalida{i};
    }
    elementos_[i - inicio_] = valor;
    inicializados_[i - inicio_] = true;
}

string Vetor::valor(int i) const{
    if(inicializados_[i - inicio_] == false){
        throw SemElementoNaPosicao{i};
    }
    if(i<inicio_ || i>fim_){
        throw PosicaoInvalida{i};
    }
    return elementos_[i - inicio_];
}

Vetor::~Vetor(){
    delete[] elementos_;
    delete[] inicializados_;
}