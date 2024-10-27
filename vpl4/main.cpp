#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    string palavra;
    map<string, int> m;
    while(cin>> palavra){
        m[palavra]++;
    }
    int max = 0;
    string b;
    for(auto it = m.begin(); it!=m.end();it++){
        if((*it).second > max){
            max = (*it).second;
            b = (*it).first;
        }
    }
    cout<< b <<" "<<max<<endl;
}

//deixar o codigo mais simples de se ler