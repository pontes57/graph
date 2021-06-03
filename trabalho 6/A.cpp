/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - previo contains the minimum cut. If previo[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

#include <string.h>
#include<iostream>
#include<algorithm>
using namespace std;
// the maximum number of vertices
#define NN 40

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, previo[NN];

int fordFulkerson( int n, int s, int t )
{
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( previo, -1, sizeof( previo ) );
        qf = qb = 0;
        previo[q[qb++] = s] = -2;
        while( qb > qf && previo[t] == -1 )
            for( int u = q[qf++], v = 0; v < n; v++ )
                if( previo[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
                    previo[q[qb++] = v] = u;

        // see if we're done
        if( previo[t] == -1 ) break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for( int v = t, u = previo[v]; u >= 0; v = u, u = previo[v] )
            bot = min(bot,cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for( int v = t, u = previo[v]; u >= 0; v = u, u = previo[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

void print(){
    for (int i = 0; i < NN; i++){
        for ( int j = 0; j < NN; j++){
            cout << cap[i][j] << " ";
        }
        cout << endl;
    }
    
}
//----------------- EXAMPLE USAGE -----------------
int main()
{
    memset( cap, 0, sizeof( cap ) );
    string input;
    int n=0;//vai contar o numero de programas
    while(getline(cin, input)) {
        if(input == "") {//se a linha for vazia o caso terminou
            if(fordFulkerson( 40, 0, 39 )<n)//caso a resposta seja menor que o numero de programas eh impossivel
                cout << "!" << endl;
            else{
                for(int i=27;i<=36;i++){//percorro todos os programas
                    bool ajuda=true;
                    for(int j=1;j<=26;j++){//percoro todas as ltras
                        if(fnet[j][i]-fnet[i][j]>0){
                            cout << char(j+64);
                            ajuda=false;
                            break;
                        }
                    }
                    if(ajuda)
                        cout << "_";
                }
                cout << endl;
            }
            memset( cap, 0, sizeof( cap ) );
            n=0;
            continue;
        }
        int letra= int(input[0])-64;//dessa forma a letra A vai ser 1 e assim por diante
        int valor= input[1]-'0';
        cap [0][letra]=valor;//posicao 0 eh o nodo artificial de comeco
        n+=valor;
        for(int i=3;i<input.length()-1;i++){
            valor=input[i]-'0';//pego o computador que pode ser executado
            cap[letra][valor+27]=1;//os computadores comecam a partir do nodo 27
            cap[valor+27][39]=1;//posicao 39 eh o nodo artificial de fim
        }
    }
    //daqui a pra baixo eh a repeticao daquele primeiro if
    if(fordFulkerson( 40, 0, 39 )<n)
        cout << "!" << endl;
    else{
        for(int i=27;i<=36;i++){
            bool ajuda=true;
            for(int j=1;j<=26;j++){
                if(fnet[j][i]-fnet[i][j]>0){
                    cout << char(j+64);
                        ajuda=false;
                        break;
                }
            }
            if(ajuda)
                cout << "_";
        }
        cout << endl;
    }
    return 0;
}