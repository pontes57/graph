#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

void gira(queue<pair<string,pair<string,int>>>&fila,vector<pair<string,pair<string,int>>>&criados,bool esta[]){
    while (!fila.empty()){
        string novo;
        char aux1,aux2;
        int pos;
        int cont;
        string operacao;
        pair<string,int>par;
        for (int i = 0; i < 3; i++){//faco as operacoes na horizontal,as operacoes estao ao contrario por estar saindo da resposta para o problema
            novo=fila.front().first;
            cont=fila.front().second.second;
            operacao=fila.front().second.first;
            aux1=novo[0+3*i];
            aux2=novo[1+3*i];
            novo[1+3*i]=novo[2+3*i];
            novo[2+3*i]=aux1;
            novo[0+3*i]=aux2;
            pos=stoi(novo);//pego o numero
            if(!esta[pos]){//se eu ainda nao tiver acessado esse vertice
                if(i==0)operacao+="1H";//inverto a posicao da letra com o numero porque vou dar saida ao contrario
                if(i==1)operacao+="2H";
                if(i==2)operacao+="3H";
                fila.push(make_pair(novo,make_pair(operacao,cont+1)));
                criados.push_back(make_pair(novo,make_pair(operacao,cont+1)));
                esta[pos]=true;
            }
        }
        for (int i = 0; i < 3; i++){//faco as operacoes na vertical,as operacoes estao ao contrario por estar saindo da resposta para o problema
            novo=fila.front().first;
            cont=fila.front().second.second;
            operacao=fila.front().second.first;
            aux1=novo[0+i];
            aux2=novo[3+i];
            novo[0+i]=novo[6+i];
            novo[3+i]=aux1;
            novo[6+i]=aux2;
            pos=stoi(novo);//pego o numero
            if(!esta[pos]){//se eu ainda nao tiver acessado esse vertice
                if(i==0)operacao+="1V";//inverto a posicao da letra com o numero porque vou dar saida ao contrario
                if(i==1)operacao+="2V";
                if(i==2)operacao+="3V";
                fila.push(make_pair(novo,make_pair(operacao,cont+1)));
                criados.push_back(make_pair(novo,make_pair(operacao,cont+1)));
                esta[pos]=true;
            }
        }
        fila.pop();
    }
}

int main(){
    queue<pair<string,pair<string,int>>>fila;//fila para bfs guarda o vertice,a sequencia de operacoes e o numero de operacoes feita
    vector<pair<string,pair<string,int>>>criados;//vetor que guarda os vertices ja visitados guarda o vertice,a sequencia de operacoes e o numero de operacoes feita
    string comeco="123456789";//primeiro vertice
    bool *esta=new bool[1000000000];//vetor pra saber se ja visitei esse vertice
    for (int i = 0; i < 1000000000; i++){
        esta[i]=false;
    }
    fila.push(make_pair(comeco,make_pair("",0)));
    criados.push_back(make_pair(comeco,make_pair("",0)));
    gira(fila,criados,esta);
    for(int i =0;i<criados.size();i++){
        string temp=criados[i].first;
        cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
        cout << temp[3] << " " << temp[4] << " " << temp[5] << endl;
        cout << temp[6] << " " << temp[7] << " " << temp[8] << endl;
    }
    while (true){
        string p,s,t;
        getline(cin,p);
        if(p[0]=='0')
            break;
        p.erase(p.begin()+1);//apago o espaco
        p.erase(p.begin()+2);//apago o espaco
        getline(cin,s);
        s.erase(s.begin()+1);//apago o espaco
        s.erase(s.begin()+2);//apago o espaco
        getline(cin,t);
        t.erase(t.begin()+1);//apago o espaco
        t.erase(t.begin()+2);//apago o espaco
        p+=s;
        p+=t;
        int max=criados.size();
        bool esta=false;
        int cont=1;
        string operacao;
        for(int j=0;j<max;j++){//vou percorrer o vetor que guarda todos os filhos
            if(p==criados[j].first){//se eh um filho
                cont=criados[j].second.second;//pego o numero de operacoes
                operacao=criados[j].second.first;//a sequencia de operacoes
                esta=true;
                break;
            }
        }
        if(esta){
            //cout << cont << " ";
            for (int i = operacao.size()-1; i >=0; i--){//dou saida ao contrario porque eu sai da resposta para o problema
                //cout << operacao[i];
            }
            //cout << endl;
        }
        //else
            //cout << "Not solvable" << endl;
    }
    return 0;
}