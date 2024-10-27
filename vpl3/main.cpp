#include <iostream>
#include <vector>

int main(){
    int l1,l2,c2;
    
    std::cout<<"digite o numero de linhas da matriz1: "<<std::endl;
    std::cin>> l1;
    std::cout<<"digite o numero de colunas da matriz1 e o numero de linhas da matriz2"<<std::endl;
    std::cin>> l2;
    std::cout<<"digite o numero de colunas da matriz2"<<std::endl;
    std::cin>> c2;
    std::cout<<std::endl;
    std::vector<std::vector<int>> matriz1(l1, std::vector<int>(l2));
    std::vector<std::vector<int>> matriz2(l2, std::vector<int> (c2));
    std::vector<std::vector<int>> matriz3(l1, std::vector<int> (c2));
    for(int i = 0; i<l1; i++){
        for(int j=0; j<l2;j++){    
            std::cin>>matriz1[i][j];  
        }
        std::cout<<std::endl;
    }
    for(int i= 0; i<l2;i++){
        for(int j=0; j<c2;j++){
            std::cin>>matriz2[i][j];
        }
        std::cout<<std::endl;
    }

    for(int i=0;i<l1;i++){
        for(int j=0; j<c2;j++){
            for(int p=0;p<l2;p++){
                matriz3[i][j] += matriz1[i][p] * matriz2[p][j];
            }
        }
    }

    for(int i = 0;i<l1;i++){
        for(int j= 0;j<c2;j++){
            std::cout<<matriz3[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

//melhoria ler as entradas em formato de matriz