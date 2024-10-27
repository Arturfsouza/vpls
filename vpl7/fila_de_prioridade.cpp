#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
    if(tamanho()==0){
        lista_.push_front(p);
    }
    else{
        auto it = lista_.begin();
        while (it != lista_.end() && it->prioridade>=p.prioridade)
        {
            it++;
        }
        lista_.insert(it, p);
    }
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome;
  nome = lista_.front().nome;
  lista_.pop_front();
  return nome;
}

void FilaDePrioridade::Remover(string nomeex) {
    for(auto it = lista_.begin(); it != lista_.end(); it++){
        if(it->nome == nomeex){
            lista_.erase(it);
            break;
        }
    }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;
  int i = 0;
  for(auto it = lista_.begin(); it != lista_.end(); it++){
    v.push_back(it->nome);
    i++;
  }
  return v; 
}

