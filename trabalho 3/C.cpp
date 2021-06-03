#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int resolve(){
    int s,t;
    cin >> s >> t;
    if(s>t)
        return -1;
    if(s==t)
        return 0;
    int aux;
    vector<int>primos;//vetor que guarda os numero primos
    queue<int>div[t+1];//matriz que guarda os fatores cada numero
    for(int i=2 ; i<=t ; i++){//acho todos os numeros primos ate t
        bool primo=true;
        aux=sqrt(i);
        for(int j=2 ; j<=aux ; j++)
            if(i%j==0){
                primo=false;
                break;
            }
        if(primo)
            primos.push_back(i);
        for (int j = 0; j < primos.size(); j++){//vou dividir o numero i por todos os primos assim eu sei quais sao os fatores de i
            if (i%primos[j]==0 && i!=primos[j])
                div[i].push(primos[j]);
        }
    }
    queue<int>fila;
    fila.push(s);
    int cont=0;
    int aux2,aux3;
    while (!fila.empty()){
        aux=fila.size();
        for (int i = 0; i < aux; i++){
            aux2=div[fila.front()].size();
            for(int j=0;j<aux2;j++){
                aux3=div[fila.front()].front()+fila.front();//somo um fator do numero ao numero
                if(aux3==t)//se for igual tenho a resposta
                    return cont+1;
                if(aux3<t){//se for menor insiro o filho na fila
                    div[fila.front()].pop();
                    fila.push(aux3);
                }
                else//se for maior nao me serve
                    div[fila.front()].pop();//eu retiro pois assim caso o numero seja novamente inserido na fila eu nao irei fazer nenhuma operacao com ele evitando perda de tempo
            }
            fila.pop();
        }
        cont++;
    }
    return -1;//se chegou ate aqui ninguem encontrou a resposta
}

int main(){
    int v;
    cin >>v;
    for (int i = 0; i < v; i++){
       cout << "Case " << i+1 << ": " << resolve() << endl;
    }
    return 0;
}