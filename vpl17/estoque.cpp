#include <string>
#include "estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  estoque.insert({mercadoria, qtd});
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  int qtd1 = estoque.find(mercadoria)->second;
  qtd1 = qtd1 - qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  for(auto it=estoque.begin(); it!=estoque.end(); it++){
    if(it->first == mercadoria){
      return it->second;
    }
  }
}

void Estoque::imprime_estoque() const {
  // TODO
  for(auto it=estoque.begin(); it!=estoque.end(); it++){
    std::cout<<it->first<<", "<<it->second<<std::endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  // TODO
  
  for(auto it = rhs.estoque.begin(); it!= rhs.estoque.end(); it++){
    add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  // TODO
  for(auto it = rhs.estoque.begin(); it!=rhs.estoque.end();it++){
    for(auto it2 = estoque.begin();it!=estoque.end();it++){
      if(it->first == it2->first){
        estoque.erase(it);
      }
    }
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  // TODO
  if(lhs.estoque.size()<=rhs.estoque.size()){
    return false;
  }
  for(auto it=lhs.estoque.begin();it!=lhs.estoque.end(); it++){
    if(rhs.estoque.find(it->first)==rhs.estoque.end()){
      return false;
    }
  }
  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  // TODO
  if(rhs.estoque.size()<=rhs.estoque.size()){
    return false;
  }
  for(auto it=rhs.estoque.begin(); it!=rhs.estoque.end(); it++){
    if(lhs.estoque.find(it->first)==lhs.estoque.end()){
      return false;
    }
  }
  return true;
}