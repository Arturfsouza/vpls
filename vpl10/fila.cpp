#include "fila.h"
#include <iostream>

Fila::Fila(){
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

string Fila::primeiro(){
    if(vazia() == 1){
        throw std::runtime_error("lista vazia!");
    }
    return(primeiro_->chave);
}

string Fila::ultimo(){
    if(vazia() == 1){
        throw std::runtime_error("Lista vazia!");
    }
    return(ultimo_->chave);
}

bool Fila::vazia(){
    return(primeiro_ == nullptr);
}

void Fila::Inserir(string k){
    if(vazia() == 1){
        primeiro_ = new No{k, nullptr};
        ultimo_ = primeiro_;
    }
    else{
    No* p = new No{k ,nullptr};
    ultimo_-> proximo = p;
    ultimo_ = p;
    }
}

void Fila::Remover(){
    No* aux = primeiro_;
    primeiro_= aux->proximo;  
    delete aux;
}

int Fila::tamanho(){
    int s = 0;
    for(No* it = primeiro_; it!=nullptr; it = it->proximo){
        s++;
    }
    return s;
}

Fila::~Fila(){
    while(primeiro_ != nullptr){
        No* aux = primeiro_;
        primeiro_ = primeiro_->proximo;
        delete aux;
    }
}