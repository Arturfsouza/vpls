#include <iostream>
#include "vetor.h"

using std::cin;
using std::cout; 
using std::endl;
using std::string;

int main() {
  try {
    int inicio, fim;
    cin >> inicio >> fim;
    Vetor v(inicio, fim);
    char opcao;
    while (cin >> opcao) {
      int indice;
      string valor;
      if (opcao == 'a') {
        cin >> indice;
        cin >> valor;
        v.atribuir(indice, valor);
      } else if (opcao == 'v') {
        cin >> indice;
        valor = v.valor(indice);
        cout << valor << endl;
      } else if (opcao == 'f') {
        return 0;
      } else {
        cout << "Opção inválida!" << endl;
      }
    }
  }
  catch(FimMenorQueInicio e){
    cout<<"Nao foi possivel realizar a operacao pois o intervalo "<<e.inicio<<" , "<<e.fim<<" eh vazio!"<<endl;
  }
  catch(PosicaoInvalida e){
    cout<<"Nao foi possivel realizar a operacao pois a posicao "<<e.posicao<<"nao esta no intervalo do vetor"<<endl;
  }
  catch(SemElementoNaPosicao e){
    cout<<"Nao foi possivel realizar a operacao pois nao ha elementos na posicao "<<e.posicao<<endl;
  }
  catch (...) {
    cout << "Erro desconhecido!" << endl;
  }
  return 0;
}

//conferir se esta tudo rodando certo, principalmente as excecoes e as posicoes