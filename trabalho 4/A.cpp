#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <iomanip>   
using namespace std;

class unionfind//classe feita em sala
{
private:
    vector<int>pai;
public:
    unionfind(int v){
        pai=vector<int>(v);
        for (int i = 0; i < v; i++){
            pai[i]=i;
        }
    }
    int find(int n){
        if(pai[n]==n)
            return n;
        int temp=find(pai[n]);
        pai[n]=temp;
        return temp;
    }
    void insere(int i,int j){
        pai[find(i)]=pai[find(j)];
    }
    bool juntos(int i,int j){
        return find(i)==find(j);
    }
    
};


void calcula(vector<pair<double,double>>&lv,vector<pair<double,pair<int,int>>>&la){//essa funcao calcula a distancia dos pontos e o coloca na lista de adjacencia
    for (int i = 0; i < lv.size()-1; i++){
        for (int j = i+1; j < lv.size(); j++){
            double x=lv[i].first-lv[j].first;
            double y=lv[i].second-lv[j].second;
            double distancia=sqrt(x*x+y*y);
            la.push_back(make_pair(distancia,make_pair(i,j)));
        } 
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        vector<pair<double,double>>lv;
        double x,y;
        for ( int j = 0; j < v; j++){
            cin >> x >>y;
            lv.push_back(make_pair(x,y));
        }
        vector<pair<double,pair<int,int>>>la;//lista de adjacencia que guarda as arestas e as suas distancias
        calcula(lv,la);
        sort(la.begin(),la.end());
        unionfind objeto(v);
        double resultado=0;
        for(int j=0;j<la.size();j++){
            if(!objeto.juntos(la[j].second.first,la[j].second.second)){//se nao estiverem no mesmo grafo
                resultado+=la[j].first;
                objeto.insere(la[j].second.first,la[j].second.second);
            }
        }
        cout << fixed << setprecision(2) << resultado << endl;
        if(i!=n-1)
            cout << endl;
    }
    return 0;
}