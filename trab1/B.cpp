#include<iostream>
#include<vector>
#include<list>
using namespace std;

class euleriano{
private:
public:
    int ** matriz;//matriz de adjacencia
    int arestas;
    vector<list<int>> ciclos;//vetor que vai guardar todos os ciclos
    euleriano(){//cria e inicializa a matriz
        matriz=new int *[51];
        for (int i = 1; i < 51; i++){
            matriz[i]=new int [51];
            for (int j = 1; j < 51; j++){
                matriz[i][j]=0;
            }
        }
    }
    ~euleriano(){
        for(int i=1;i<51;i++)
            delete[]matriz[i];
        delete[]matriz;
    }
    void preenche(){//preenche a matriz de adjacencia
        cin >> arestas;
        int primeiro,segundo;
        for (int i = 0; i < arestas; i++){
            cin >> primeiro;
            cin >> segundo;
            matriz[primeiro][segundo]++;
            if(primeiro!=segundo)
                matriz[segundo][primeiro]++;
        }
    }
    bool insere(int posicao,int linha){//insere o elemento num ciclo
        if (posicao==ciclos[linha].front())//caso seja igual ao elemento que começa o ciclo o ciclo esta feito
            return true;
        ciclos[linha].push_back(posicao);//insere o elemento
        for(int i=1;i<51;i++){
            if(matriz[posicao][i]>0){//procura um vertice adjacente a ele
                matriz[posicao][i]--;//apaga essa aresta
                if(posicao!=i)
                    matriz[i][posicao]--;//apaga essa aresta
                arestas--;//diminui o numero de arestas
                return insere(i,linha);//chama a funçao para inserir esse nodo adjacente
            }
        }
        return false;//se chegou ate aqui é pq nao tem nodo adjacente entao deu errado
    }

    bool comeca(int linha){//funçao que começa a insercao
        for(int k=1;k<51;k++){
            for(int j=1;j<51;j++)
                if(matriz[k][j]>0){//procura a primeira aresta da matriz
                    matriz[k][j]--;//apaga a aresta
                    if(j!=k)
                        matriz[j][k]--;//apaga a aresta
                    arestas--;//diminui o numero de aresta
                    ciclos[linha].push_back(k);//insere esse nodo
                    return insere(j,linha);//e chama a funçao para inserir o proximo
                }
        }
        return false;//se chegou aqui é pq nao tem aresta alguma na matriz logo deu errado
    }

    bool crialista(){// funcao que vai criar os ciclos
        for(int i=0;arestas!=0;i++){
            list<int>linha;//para cada ciclo
            ciclos.push_back(linha);
            if(!comeca(i)){//comeco o ciclo
                return false;
            }
            list<int>::iterator it;
            it=ciclos[i].begin();
            ciclos[i].push_back(*it);//para completar o ciclo
        }
        return true;
    }
    void reverte(int posicao,list<int>::iterator it,list<int>::iterator it2){
        list<int>::iterator aux;
        ciclos[posicao].pop_back();
        for (aux = it2;aux!=ciclos[posicao].end(); aux++){
            ciclos[0].insert(it,*aux);
        }
        for (aux = ciclos[posicao].begin();aux!=it2; aux++){
            ciclos[0].insert(it,*aux);
        }
    }

    bool final(){//funcao que une os ciclos
        while (ciclos.size()!=1){//enquanto houver mais de um ciclo
            list<int>::iterator it;
            list<int>::iterator it2;
            bool sair=false;
            for(int i=1;i<ciclos.size();i++){//percorre todos os ciclos
                for(it2=ciclos[i].begin();it2!=ciclos[i].end();it2++){//percorre toda a lista 
                    for(it=ciclos[0].begin();it!=ciclos[0].end();it++){//percorre toda a primeira lista
                        if(*it==*it2){//se tem elemente em comum da para inserir
                            reverte(i,it,it2);//insere uma lista na outra
                            ciclos.erase(ciclos.begin()+i);//apaga a lista
                            sair=true;//avisa que é pra recomeçar a procura
                            break;
                        }
                        if(sair) break;
                    }
                    if(sair) break;
                }
                if(sair) break;
            }
            if(sair) continue;
        return false;//se chegou aqui nao conseguiu unir os ciclos logo deu errado
        }
        return true;
    }
    void printa(){//funcao que printa o colar na tela
        list<int>::iterator it;
        list<int>::iterator it2;
        it=ciclos[0].begin();
        cout << *it << " ";
        it++;
        it2=ciclos[0].end();
        it2--;
        for(;it!=it2;it++){
            cout << *it << endl;
            cout << *it << " ";
        }
        cout << *it2 << endl;
    }
    void testa(){
        for(int i=0;i<ciclos.size();i++){
            list<int>::iterator it;
            list<int>::iterator it2;
            it=ciclos[i].begin();
            while(true){
                it2=it;
                if(it2++==ciclos[i].end()) break;
                cout << *it << " ";
                it++;
            }
            cout << endl;
        }
    }
};

int main(){
    int v;
    cin >> v;
    for (int i = 0; i < v; i++){
        cout << "Case #" << i+1 << endl;
        euleriano objeto;
        objeto.preenche();
        if(!objeto.crialista()){
            cout << "some beads may be lost" <<endl;
            cout << endl;
            continue;
        }
        //objeto.testa();
        if(!objeto.final()){
            cout << "some beads may be lost" <<endl;
            cout << endl;
            continue;
        }
        objeto.printa();
        cout << endl;
    }
    return 0;
}