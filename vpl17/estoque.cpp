#include <string>
#include "estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  if(estoque.find(mercadoria) !=estoque.end()){
    estoque.find(mercadoria)->second += qtd;
  }
  else
  {
  estoque.insert({mercadoria, qtd});
  }
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if(estoque.find(mercadoria)!=estoque.end()){
    if(estoque.find(mercadoria)->second - qtd<0){
      estoque.find(mercadoria)->second = estoque.find(mercadoria)->second -qtd;
    }
    else{
      std::cout<<mercadoria<<" insuficiente"<<std::endl;
    }
  }
  else{
    std::cout<<mercadoria<<" inexistente"<<std::endl;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  /*for(auto it=estoque.begin(); it!=estoque.end(); it++){
    if(it->first == mercadoria){
      return it->second;
    }
  }*/
  if(estoque.find(mercadoria)!=estoque.end()){
    return estoque.find(mercadoria)->second;
  }
  else{
    return 0;
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