#include<iostream>
#include<vector>
#include<string>
using namespace std;

int recursiva(vector <int>La[],int posicao,int ignora){//funcao para contar o numero de nodos de uma arvore
    int soma=0;
    for (int i = 0; i < La[posicao].size(); i++){//vai em todos os vertices adjacentes a esse vertice
        if (La[posicao][i]==ignora){//caso seja o vertice de onde ele veio nao faz nada
            continue;
        }
        soma+=recursiva(La,La[posicao][i],posicao);//pega a soma de todos os vertices adjacente a ele
    }
    return soma+1;//adiciona 1 a mais
}

int eventree(int vertices,int arestas,int primeiro[], int segundo[]){
    int cont=0;
    vector <int>La[vertices+1];//lista de adjacencia
    for (int i = 0; i < arestas; i++){//preencho a lista de adjacencia
        La[primeiro[i]].push_back(segundo[i]);
        La[segundo[i]].push_back(primeiro[i]);
    }
    for (int i = 0; i < arestas; i++){
        if(recursiva(La,primeiro[i],segundo[i])%2==0 && recursiva(La,segundo[i],primeiro[i])%2==0)//caso a ambas as duas arvores tenha o numero de nodos par
            cont++;
    }
    return cont;
}

int main(){
    int vertices,arestas;
    cin >> vertices;
    cin >> arestas;
    int primeiro[100];
    int segundo[100];
    for (int i = 0; i < arestas; i++){
        cin >>primeiro[i];
        cin >>segundo[i];
    }
    //até aqui só criei e preenchi os vertices e arestas
    cout << eventree(vertices,arestas,primeiro,segundo)<<endl;
    return 0;
}