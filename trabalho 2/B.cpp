#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){//nesse programa eu basicamente cerco os lobos com cachorros,se eu nao conseguir eh impossivel
    int r,c;
    cin >> r >> c;
    vector<string>matriz;
    for (int i = 0; i < r; i++){
        string linha;
        cin >> linha;
        matriz.push_back(linha);
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(matriz[i][j]=='W'){
                if((i+1)<r){
                    if(matriz[i+1][j]=='S'){
                        cout << "No" << endl;
                        return 0;
                    }
                    if(matriz[i+1][j]=='.')
                        matriz[i+1][j]='D';
                }
                if((i-1)>=0){
                    if(matriz[i-1][j]=='S'){
                        cout << "No" << endl;
                        return 0;
                    }
                    if(matriz[i-1][j]=='.')
                        matriz[i-1][j]='D';
                }
                if((j+1)<c){
                    if(matriz[i][j+1]=='S'){
                        cout << "No" << endl;
                        return 0;
                    }
                    if(matriz[i][j+1]=='.')
                        matriz[i][j+1]='D';
                }
                if((j-1)<c){
                    if(matriz[i][j-1]=='S'){
                        cout << "No" << endl;
                        return 0;
                    }
                    if(matriz[i][j-1]=='.')
                        matriz[i][j-1]='D';
                }
            }
        }
    }
    cout << "Yes"<<endl;
    for (int i = 0; i < r; i++)
        cout << matriz[i] << endl;
    
    return 0;
}
