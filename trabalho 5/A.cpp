#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<pair<int,int>>>Listad;//lista de adjacencia
vector<string>indice;//cada poiscao eh um vertice e o valor eh o seu nome

void insere(string itema,string itemb,int a){
    int indicea=-1,indiceb=-1;
    for (int i = 0; i < indice.size(); i++){
        if(itema==indice[i])//caso o item ja esteja na lista eu pego o seu identificador
            indicea=i;
        if (itemb==indice[i])//caso o item ja esteja na lista eu pego o seu identificador
            indiceb=i;
    }
    if(indicea==-1){//caso ele nao estaja na lista eu pego seu identificador e insiro ele
        indicea=indice.size();
        indice.push_back(itema);
        vector<pair<int,int>> vazio;
        Listad.push_back(vazio);
    }
    if(indiceb==-1){//caso ele nao estaja na lista eu pego seu identificador e crio a sua lista de adjacencia
        indiceb=indice.size();
        indice.push_back(itemb);
        vector<pair<int,int>> vazio;
        Listad.push_back(vazio);
    }
    Listad[indicea].push_back(make_pair(indiceb,a));//insiro o valor
    Listad[indiceb].push_back(make_pair(indicea,a));//insiro o valor
}



int main(){
    int c,r,vezes=1;
    cin >> c >>r;
    while (c!=0 && r!=0){
        Listad.clear();
        indice.clear();
        string a;
        string b;
        int n;
        for (int i=0;i<r;i++){
            cin >> a >> b >> n;
            insere(a,b,n);
        }
        cin >> a >> b;
        n=indice.size();
        int dist[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=0;//como quero o caminho maximo inicilizo com 0
        for (int i = 0; i < Listad.size(); i++)
            for (int j = 0; j < Listad[i].size(); j++)
                dist[i][Listad[i][j].first]=Listad[i][j].second;//inicializando as arestas
        for (int k = 0; k < n; k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(dist[i][k]!=0 && dist[k][j]!=0)
                        dist[i][j]=max(dist[i][j],min(dist[i][k],dist[k][j]));//pego o minimo entre os dois novos possiveis caminhos pq quero a menor aresta no caminho
        int begin,fim;
        for (int i=0;i<n;i++){
            if(indice[i]==a)
                begin=i;
            if(indice[i]==b)
                fim=i;
        }
        cout << "Scenario #" << vezes << endl << dist[begin][fim] << " tons" << endl << endl;
        vezes++;
        cin >> c >>r;
    }
    return 0;
}