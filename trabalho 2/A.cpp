#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<pair<int,pair<int,int>>>>Listad;//lista de adjacencia que guarda o identificador do vertice e os valores da troca
vector<string>indice;//cada poiscao eh um vertice e o valor eh o seu nome

void insere(string itema,string itemb,int a,int b){
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
        vector<pair<int,pair<int,int>>> vazio;
        Listad.push_back(vazio);
    }
    if(indiceb==-1){//caso ele nao estaja na lista eu pego seu identificador e crio a sua lista de adjacencia
        indiceb=indice.size();
        indice.push_back(itemb);
        vector<pair<int,pair<int,int>>> vazio;
        Listad.push_back(vazio);
    }
    Listad[indicea].push_back(make_pair(indiceb,make_pair(a,b)));//insiro o valor
    Listad[indiceb].push_back(make_pair(indicea,make_pair(b,a)));//insiro o valor
}

int mdc (int a, int b) {//maximo divisor comum
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

pair<int,int> busca(bool visitados[],int posicao,int objetivo){
    int divisor=1;
    if(visitados[objetivo])//caso o objetivo ja tenha sido encontrado
        return make_pair(0,0);
    for (int i = 0; i < Listad[posicao].size(); i++){//percorro meus filhos
        if(visitados[Listad[posicao][i].first])//caso ja tenha sido visitado nao faz nada
            continue;
        if(Listad[posicao][i].first==objetivo){//caso seja o objetivo
            divisor=mdc(Listad[posicao][i].second.first,Listad[posicao][i].second.second);
            visitados[objetivo]=true;
            return make_pair(Listad[posicao][i].second.first/divisor,Listad[posicao][i].second.second/divisor);//retorno ja simplificado
        }
        else{//caso nao seja visitado
            visitados[Listad[posicao][i].first]=true;
            pair<int,int>resultado=busca(visitados,Listad[posicao][i].first,objetivo);
            if(resultado.first==0)//caso meu filho nao de em nada
                continue;
            else{//caso meu filho ache o objetivo
                int a=resultado.first*Listad[posicao][i].second.first;
                int b=resultado.second*Listad[posicao][i].second.second;
                divisor=mdc(a,b);
                return make_pair(a/divisor,b/divisor);//retorno o valor multiplicado e simplicado pelo meu numero
            }
        }
    }
    return make_pair(0,0);
}
int main(){
    char operacao;
    while (cin>>operacao){
        if(operacao=='.'){
            return 0;
        }
        if(operacao=='!'){
            string itema,itemb;
            char ignora;
            int a,b;
            cin >> a;
            cin >> itema;
            cin >> ignora;
            cin>>b;
            cin>>itemb;
            insere(itema,itemb,a,b);
        }
        if(operacao=='?'){
            bool visitados[indice.size()];
            for (int i = 0; i < indice.size(); i++){
                visitados[i]=false;
            }
            string itema,itemb;
            char ignora;
            cin >> itema;
            cin >> ignora;
            cin >> itemb;
            int indicea,indiceb;
            for (int i = 0; i < indice.size(); i++){
                if(itema==indice[i])
                    indicea=i;
                if (itemb==indice[i])
                    indiceb=i;
            }
            visitados[indicea]=true;
            pair<int,int>resultado=busca(visitados,indicea,indiceb);
            if(resultado.first==0)
                cout << "? "<<itema<<" = ? "<<itemb<<endl;
            else
                cout << resultado.first <<" "<<itema<<" = "<<resultado.second<<" "<<itemb<<endl;
        }
    }
}