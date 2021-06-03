#include<iostream>
#include<vector>
using namespace std;

class matrizin{
    private:
    public:
        int vertices,arestas;
        int ** matriz;//a possivel matriz de incidencia
        matrizin(){//cria e preenche a matriz
            cin >> vertices;
            cin >> arestas;
            matriz=new int *[vertices];
            for (int i = 0; i < vertices; i++){
                matriz[i]=new int [arestas];
                for (int j = 0; j < arestas; j++){
                    cin >> matriz[i][j];
                }
            }
        }
        ~matrizin(){
            for (int i = 0; i < vertices; i++){
                delete[]matriz[i];
            }
            delete[]matriz;
        }
        void testa(){//vai testa se é uma matriz de incidencia ou nao
            int cont;
            for (int i = 0; i < arestas; i++){//percorre todas as colunas
                cont=0;
                for (int j = 0; j < vertices; j++){//percorre todas as linhas
                    if(matriz[j][i]==1)//se a aresta for incidente nesse vertice
                        cont++;
                }
                if (cont!=2){//caso o numero de vertices em que a aresta incide seja diferente de 2
                    cout << "No" << endl;//nao é incidente
                    return;
                }
            }
            int cont1=0;
            for (int i = 0; i < arestas-1; i++){//percorre todas as colunas
                for ( int j = i+1; j < arestas; j++){//percorre todas as colunasa a frente da atual coluna
                    cont1=0;
                    for (int k = 0; k < vertices; k++){//percorre todas as linhas
                        if(matriz[k][i]== 1 && matriz[k][j]==1)//caso ambas as aresta incidam no mesmo vertice
                            cont1++;
                    }
                    if (cont1>1){//caso as aresta conectem os mesmo dois vertices
                        cout << "No" << endl;//nao é incidente
                        return;
                    }
                }
            }
            cout << "Yes" << endl; //se passou pelos testes é incidente

        }
};
int main(){
    int v;
    cin >> v;
    for (int i = 0; i < v; i++){
    matrizin objeto;//cada objeto é uma matriz
    objeto.testa();
    }
    return 0;
}