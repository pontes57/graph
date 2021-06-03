#include<iostream>
#include<vector>
using namespace std;

int recursiva(int posicao,int empregados[]){
    if(empregados[posicao]==-1)
        return 1;//caso seja raiz
    return 1+recursiva(empregados[posicao],empregados);//soma ele mais os pais
}

int main(){
    int n;
    cin >>n;//numero de empregados
    bool isfolha[n+1];//para saber se o empregado nao é chefe de ninguem
    int empregados[n+1];//cada posicao é um empregado e o valor é o seu chefe
    for (int i = 1; i <=n; i++){
        isfolha[i]=true;
    }
    for (int i = 1; i <=n; i++){
        cin >>empregados[i];//faço a entrada
        if(empregados[i]!=-1)//caso o empregado tem chefe
            isfolha[empregados[i]]=false;//esse empregado é chefe de alguem
    }
    int resultado=0;
    int maior=0;
    for (int i = 1; i <=n; i++){
        if(isfolha[i]){//caso nao tenha chefe
            resultado=recursiva(i,empregados);//vai achar o nivel do nodo
            if(resultado>maior)//caso seja o maior nivel salva
                maior=resultado;
        }
    }
    cout << maior << endl;//cada grupo sera formado por pessoas do mesmo nivel mesmo que sejam de arvores diferentes entao a resposta é a altura da maior arvore
    return 0;
}