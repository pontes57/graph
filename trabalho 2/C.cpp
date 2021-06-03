#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

void resolve (){
    int r,c;//linhas e colunas
    cin >> r >> c;
    vector<string>matriz;//guarda o labirinto
    queue<pair<int,int>>joe;//fila do joe
    queue<pair<int,int>>fogo;//fila do fogo
    for (int i = 0; i < r; i++){//entrada
        string linha;//linha da entrada
        cin >> linha;
        for ( int j = 0; j < c; j++){
            if(linha[j]=='F'){//caso tenha um fogo na linha
                pair <int,int> aux;
                aux=make_pair (i,j);
                fogo.push(aux);//guardo a posicao desse fogo
            }
            if(linha[j]=='J'){//caso tenha um joe na linha
                pair <int,int> aux;
                aux=make_pair (i,j);
                joe.push(aux);//guardo a posicao desse joe
            }
        }
        matriz.push_back(linha);//guardo a linha
    }
    int cont=0;//contador pra quantos minutos passaram
    while (true){
        int aux=joe.size();
        for (int i = 0; i < aux; i++){//vou percorrer todos os joe que estiverem na fila nesse momento
            pair <int,int> atual=joe.front();//pego o joe
            joe.pop();//tiro ele da fila
            if(matriz[atual.first][atual.second]!='J')//caso um fogo ja tenha consumido ele eu termino
                continue;
            if((atual.first+1)==r){//caso ele sai pra fora da matriz ganhou
                cout << cont+1 << endl;
                return;
            }
            if((atual.first-1)==-1){//caso ele sai pra fora da matriz ganhou
                cout << cont+1 << endl;
                return;
            }
            if((atual.second+1)==c){//caso ele sai pra fora da matriz ganhou
                cout << cont+1 << endl;
                return;
            }
            if((atual.second-1)==-1){//caso ele sai pra fora da matriz ganhou
                cout << cont+1 << endl;
                return;
            }
            if(matriz[atual.first+1][atual.second]=='.'){//caso a proxima posicao esteja vazia
                matriz[atual.first+1][atual.second]='J';//me coloco nessa posicao
                pair <int,int> novo;
                novo=make_pair (atual.first+1,atual.second);
                joe.push(novo);//guardo a nova posicao
            }
            if(matriz[atual.first-1][atual.second]=='.'){//caso a proxima posicao esteja vazia
                matriz[atual.first-1][atual.second]='J';//me coloco nessa posicao
                pair <int,int> novo;
                novo=make_pair (atual.first-1,atual.second);
                joe.push(novo);//guardo a nova posicao
            }
            if(matriz[atual.first][atual.second+1]=='.'){//caso a proxima posicao esteja vazia
                matriz[atual.first][atual.second+1]='J';//me coloco nessa posicao
                pair <int,int> novo;
                novo=make_pair (atual.first,atual.second+1);
                joe.push(novo);//guardo a nova posicao
            }
            if(matriz[atual.first][atual.second-1]=='.'){//caso a proxima posicao esteja vazia
                matriz[atual.first][atual.second-1]='J';//me coloco nessa posicao
                pair <int,int> novo;
                novo=make_pair (atual.first,atual.second-1);
                joe.push(novo);//guardo a nova posicao
            }
        }
        if(joe.empty()){//caso todos os joe ja tenha sido consumidos ele perdeu
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        aux=fogo.size();
        for (int i = 0; i < aux; i++){//vou percorrer todos os joe que estiverem na fila nesse momento
            pair <int,int> atual=fogo.front();//pego o fogo
            fogo.pop();//tiro ele da fila
            if(matriz[atual.first][atual.second]!='F')
                cout << "erro" << endl;
            if((atual.first+1)!=r){//caso ele sai pra fora da matriz nao faz nada
                if(matriz[atual.first+1][atual.second]=='.' || matriz[atual.first+1][atual.second]=='J'){//caso a proxima posicao esteja vazia ou seja joe
                    matriz[atual.first+1][atual.second]='F';//me coloco nessa posicao
                    pair <int,int> novo;
                    novo=make_pair (atual.first+1,atual.second);
                    fogo.push(novo);//guardo a nova posicao
                }
            }
            //repita os mesmo comentarios para os if abaixo
            if((atual.first-1)!=-1){
                if(matriz[atual.first-1][atual.second]=='.' || matriz[atual.first-1][atual.second]=='J'){
                    matriz[atual.first-1][atual.second]='F';
                    pair <int,int> novo;
                    novo=make_pair (atual.first-1,atual.second);
                    fogo.push(novo);
                }
            }
            if((atual.second+1)!=c){
                if(matriz[atual.first][atual.second+1]=='.' || matriz[atual.first][atual.second+1]=='J'){
                    matriz[atual.first][atual.second+1]='F';
                    pair <int,int> novo;
                    novo=make_pair (atual.first,atual.second+1);
                    fogo.push(novo);
                }
            }
            if((atual.second-1)!=-1){
                if(matriz[atual.first][atual.second-1]=='.' || matriz[atual.first][atual.second-1]=='J'){
                    matriz[atual.first][atual.second-1]='F';
                    pair <int,int> novo;
                    novo=make_pair (atual.first,atual.second-1);
                    fogo.push(novo);
                }
            }
        }
        cont++;     //passa o minuto
    }
}

int main(){
    int vezes;
    cin >> vezes;
    for (int i = 0; i < vezes; i++){
        resolve();
    }
    return 0;
}