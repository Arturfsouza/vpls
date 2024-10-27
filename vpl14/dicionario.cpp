#include "dicionario.h"

Dicionario::Dicionario(){

}

int Dicionario::tamanho(){
    return elementos_.size();
}

bool Dicionario::pertence(string chave){
    for(auto i = elementos_.begin(); i!=elementos_.end() ; i++){
    //for(const auto& elemento:elementos_)
        if (i->chave==chave){
            return true;
        }
    }
    return false;
}

string Dicionario::menor(){
    string menor = elementos_.begin()->chave;
    for(const auto& elemento:elementos_){
        if (elemento.chave < menor){
            menor = elemento.chave;
        }
    }
    return menor;
}

string Dicionario::valor(string chave){
    for(const auto& elemento:elementos_){
        if(elemento.chave==chave){
            return elemento.valor;
        }
    }
}

void Dicionario::Inserir(string chave, string valor){
    Elemento elemento{chave,valor};
    elementos_.push_front(elemento);
}

void Dicionario::Remover(string chave){
    for(auto it = elementos_.begin(); it!=elementos_.end(); it++){
        if(it->chave==chave){
            elementos_.erase(it);
            return;
        }
    }
}

void Dicionario::Alterar(string chave, string valor){
    for(auto it=elementos_.begin(); it!= elementos_.end(); it++){
        if(it->chave==chave){
            it->valor=valor;
            return;
        }
    }
}

Dicionario::~Dicionario(){
    elementos_.clear();
}