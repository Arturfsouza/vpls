#include <iostream>
#include <string>


int main(){
    std::string palavra;
    std::cout<<"Escreva uma palavra"<<std::endl;
    std::cin>> palavra;
    int conta= 0;
    int conte= 0;
    int conti= 0;
    int conto= 0;
    int contu= 0;
    for(int i =0; i<palavra.size();i++){
        if (palavra[i] == 'a'){
            conta++;
        }
    }
    for(int i =0; i<palavra.size();i++){
        if (palavra[i] == 'e'){
            conte++;
        }
    }
    for(int i =0; i<palavra.size();i++){
        if (palavra[i] == 'i'){
            conti++;
        }
    }
    for(int i =0; i<palavra.size();i++){
        if (palavra[i] == 'o'){
            conto++;
        }
    }
    for(int i =0; i<palavra.size();i++){
        if (palavra[i] == 'u'){
            contu++;
        }
    }
    if (conta != 0){
        std::cout<<"a "<<conta<<std::endl;
    }
    if (conte != 0){
        std::cout<<"e "<<conta<<std::endl;
    }
    if (conti != 0){
        std::cout<<"i "<<conta<<std::endl;
    }
    if (conto != 0){
        std::cout<<"o "<<conta<<std::endl;
    }
    if (contu != 0){
        std::cout<<"u "<<conta<<std::endl;
    }
    return 0;
}

//melhoria diminuir o numero de for e if