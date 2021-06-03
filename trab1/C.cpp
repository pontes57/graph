#include<iostream>
#include<vector>
#include<string>
using namespace std;

class grafo{
    private:
    public:
        vector <pair<char,char>> arestas;//vetor que guarda as arestas
        vector <char> vertices ;//vetor que guarda os vertices
        int nvertices=0,narestas=0,arvores=0,pontos=0;
        grafo(){
            string linha;
            while (cin){//enquanto tiver entrada
                cin >> linha;//pego a linha
                if (linha[0]=='*')break;//caso seja a penultima linha eu saio
                pair <char,char> letras;
                letras=make_pair (linha[1],linha[3]);//pego a aresta
                arestas.push_back(letras);//guardo a aresta
            }
            cin>>linha;//pego a linha dos vertices
            for (int i = 0; i < linha.length(); i+=2){
                vertices.push_back(linha[i]);//guardo os vertices
            }
            nvertices=vertices.size();
            narestas=arestas.size();
        }
        void testa(){
            arvores=nvertices-narestas;//numero de subgrafo conexo é V-E
            bool isponto [nvertices];//sera usado para saber qual subgrafo é ponto ou nao
            for (int i = 0; i < nvertices; i++){
                isponto[i]=true;
            }
            for (int i = 0; i < nvertices; i++){//percorro todos os vertices
                for (int j = 0; j < narestas; j++){//percorro todas as arestas
                    if(vertices[i]==arestas[j].first || vertices[i]==arestas[j].second)//caso a vertice esteja em alguma aresta
                        isponto[i]=false;//nao é ponto
                }
            }
             for (int i = 0; i < nvertices; i++){
                if(isponto[i])
                    pontos++;//conto o numero de pontos
            }
            arvores=arvores-pontos;//subtraio os pontos das arvores
            cout << "There are " <<arvores<<" tree(s) and "<<pontos<<" acorn(s)." << endl;
        }
};
int main(){
    int v;
    cin >> v;
    for (int i = 0; i < v; i++){
    grafo objeto;//cada objeto é um grafo
    objeto.testa();
    }
    return 0;
}