#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void tarjan(vector<int> La[],int ordem[],int low[],int vertice,int &posicao,int pai,int ciclos[]){
    ordem[vertice]=low[vertice]=posicao;
    posicao++;
    for(int i=0;i<La[vertice].size();i++){
        if(ordem[La[vertice][i]]!=-1 && La[vertice][i]!=pai){//caso o vertice ja tenha sido descoberto
            if (low[vertice]>ordem[La[vertice][i]]){
                low[vertice]=ordem[La[vertice][i]];
                if(low[vertice]<low[pai])//tratando para caso um dos meus filhos ache meu pai antes de eu voltar o valor do low
                    low[pai]=low[vertice];
            }
            if(low[La[vertice][i]]>ordem[vertice])//caso o low do meu filho seja maior do que eu ele nao consegue voltar para tras de mim(caso seja igual eu irei conta somente uma vez na outra parte do codigo)
                    ciclos[vertice]++;                
            continue;
        }
        if(La[vertice][i]!=pai){
            tarjan(La,ordem,low,La[vertice][i],posicao,vertice,ciclos);
            if (low[vertice]>low[La[vertice][i]]){
                low[vertice]=low[La[vertice][i]];
                if(low[vertice]<low[pai])//tratando para caso um dos meus filhos ache meu pai antes de eu voltar o valor do low
                    low[pai]=low[vertice];
                }
            if(low[La[vertice][i]]>=ordem[vertice])//caso o low do meu filho seja maior do que eu ele nao consegue voltar para tras de mim e se for igual a somente um componente conexo que volta em mim logo contarei uma vez
                ciclos[vertice]++;
        }
    }
}

void resolve(int v,int s){
    vector<int>La[v];//lista de adjacencia
    int ordem[v];//guarda a ordem dos vetores no algoritmo de tarjan
    int low[v];//guarda o low dos vetores no tarjan
    for(int i=0;i<v;i++)
        ordem[i]=-1;
    int primeiro,segundo;
    while (true){
        cin >> primeiro >> segundo;
        if (primeiro==-1)
            break;
        La[primeiro].push_back(segundo);
        La[segundo].push_back(primeiro);
    }
    int posicao=0;//essa variavel diz qual vai ser o valor do vertice no algoritmo de tarjan
    int ciclos[v];//vetor que conta quantos componentes conexos sobra se tirar o vertice
    for (int i = 0; i < v; i++)
        ciclos[i]=1;
    tarjan(La,ordem,low,0,posicao,0,ciclos);
    ciclos[0]--;//trata o caso da raiz
    pair<int,int>CP[v];//esse vetor vai guardar o valor do ciclos e a posicao para que podemos ordenar
    for (int i = 0; i < v; i++){
        CP[i]=make_pair(-ciclos[i],i);//ordena de forma negativa assim os maiores vem primeiro
    }
    sort(CP,CP+v);
    for (int i = 0; i < s; i++){
        cout << CP[i].second << " " << -CP[i].first << endl;//desnegativo o valor
    }
}

int main(){
    int v,s;
    while (true){
        cin >> v>>s;
        if(v==0)
            return 0;
        resolve(v,s);
        cout <<endl;
    }
}