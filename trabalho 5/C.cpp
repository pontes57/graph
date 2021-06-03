#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int v,a;
        cin >> v >> a;
        pair<int,pair<int,int>>arestas[a];
        for(int j=0;j<a;j++)
            cin >> arestas[j].second.first >> arestas[j].second.second >> arestas[j].first;
        // a seguir eh basicamente o bellman-ford
        int dist[v];
        for(int j=0;j<v;j++)
            dist[j]=40000000;
        dist[0]=0;
        bool possivel=false;
        for(int j=0;j<v;j++)//faco uma vez a mais para verificar se existe ciclo negativo
            for(int k=0;k<a;k++)
                if(dist[arestas[k].second.first ]+arestas[k].first<dist[arestas[k].second.second ]){
                    if(j==(v-1)){//caso seja verdade existe um ciclo negativo
                        possivel=true;
                        break;
                    }
                    dist[arestas[k].second.second ]=dist[arestas[k].second.first ]+arestas[k].first;
                }
        if (possivel)
            cout << "possible\n";
        else
            cout <<"not possible\n";
    }
    return 0;
}