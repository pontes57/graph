#include<iostream>
#include<string>
#include<vector>
using namespace std;
//nesse programa eu vejo se o grafo eh bipartido ou nao
bool recursiva(vector <int>La[],int cores[],int posicao,int minha,int outro){
    int tamanho=La[posicao].size();
    for (int i = 0; i < tamanho; i++){
        if (cores[La[posicao][i]]==-1){//caso o vertice nao seja pintado eu pinto e falo pro vertice fazer o mesmo com os filhos
            cores[La[posicao][i]]=outro;
            if(!recursiva(La,cores,La[posicao][i],outro,minha))//caso tenha dado errado no filho eu transmito a mensagem
                return false;
        }
        if (cores[La[posicao][i]]==minha)//caso tenha um filho com a minha cor deu errado
            return false;
    }
    return true;
}

void resolve(int v){
    vector <int>La[v+1];
    int cores[v+1];
    while (true){//preencho a lista de adjacencia e inicializo o vetor de cores
        int primeiro,segundo;
        cin >> primeiro >> segundo;
        if(primeiro==0 && segundo==0)
            break;
        La[primeiro].push_back(segundo);
        La[segundo].push_back(primeiro);
        cores[primeiro]=-1;
        cores[segundo]=-1;
    }
    int comeco;
    for (int i = 1; i < v+1; i++){//pego o primeiro vertice nao nulo
        if(!La[i].empty()){
            comeco=i;
            break;
        }
    }
    cores[comeco]=0;
    if(recursiva(La,cores,comeco,0,1))
        cout << "YES" << endl;
    else
        cout <<"NO"<< endl;
}

int main(){
    int v=-1;
    while (true){
        cin >> v;
        if(v==0)
            return 0;
        resolve(v);
    }
    
}