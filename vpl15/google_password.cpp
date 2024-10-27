#include "google_password.h"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  if(validPassword(password)==1){
  Usuario exemplo{login,password};
  passwords_.insert({url, exemplo});}
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
  for(auto it=passwords_.begin(); it!=passwords_.end();it++){
    if(it->first==url){
        passwords_.erase(it);
        return;
    }
  }
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  if(validPassword(new_password)==1){
  auto it = passwords_.find(url);
  it->second.login = login;
  it->second.password = new_password;}
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */
  for(auto it=passwords_.begin(); it!=passwords_.end(); it++){
    std::cout<<passwords_.size()<<std::endl<<it->first<<": "<<it->second.login<<" and "<<it->second.password<<std::endl;
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
  // TODO: Implemente este metodo
  if(password.find("123456")!=std::string::npos || password.find(" ")!=std::string::npos){
    return 0;
  }
  else if(password.size()>50 || password.size()<6){
    return 0;
  }
  else{return 1;}
}


