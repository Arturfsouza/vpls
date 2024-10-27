#include "jogo_da_vida.h"

JogoDaVida::JogoDaVida(int l, int c){
    vivas_ = std::vector<std::vector<bool>>(l, std::vector<bool>(c, false));
}

bool JogoDaVida::viva(int i, int j){
    return vivas_[i][j];
}

void JogoDaVida::Matar(int i, int j){
    vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j){
    vivas_[i][j] = true;
}

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y){
    int celulasvivas = 0;
    for(int i: {x-1,x,x+1}){
        for(int j: {y-1,y,y+1}){
            if (!(i == x && j == y)){
                int i_circular = (i + linhas()) % linhas();
                int j_circular = (j + colunas()) % colunas();
                if(viva(i_circular, j_circular)){
                    celulasvivas++;
                }
            }
        }
    }
    return celulasvivas;
}


void JogoDaVida::ExecutarProximaIteracao(){
    
    for(int i=0; i<linhas(); i++){
        for(int j=0; j<colunas(); j++){
            if(NumeroDeVizinhasVivas(i,j)>3){
                Matar(i,j);
            }
            else if (NumeroDeVizinhasVivas(i,j)<2)
            {
                Matar(i,j);
            }
            else{
                Reviver(i,j);
            }
        }
    }
    
}

