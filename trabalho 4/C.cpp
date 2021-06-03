#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <iomanip>   
using namespace std;

class unionfind
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


int main(){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        int v;
        int r;
        cin >> v;
        cin >>r;
        double x,y,f;
        vector<pair<int,pair<int,int>>>la;
        for ( int j = 0; j < r; j++){
            cin >> x >>y>>f;
            la.push_back(make_pair(-1*f,make_pair(x,y)));
        }
        sort(la.begin(),la.end());
        unionfind objeto(v);
        int menor=-1*la[0].first;
        for(int j=0;j<la.size();j++){
            if(!objeto.juntos(la[j].second.first,la[j].second.second)){
                if(menor>(-1*la[j].first))
                    menor=-1*la[j].first;
                objeto.insere(la[j].second.first,la[j].second.second);
            }
        }
        cout << "Case #" << i+1 << ": ";
        cout  << menor << endl;
    }
    return 0;
}