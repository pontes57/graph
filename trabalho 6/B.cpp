
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
#include<vector>
#include<cctype>
using namespace std;
// the maximum number of vertices
#define NN 55

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
int main(){
    memset( cap, 0, sizeof( cap ) );
    string input;
    int n1;//numero de casos
    cin >>n1;
    for(int i=0;i<n1;i++){
        int n2;//numero de programas pra cada caso
        cin >> n2;
        vector<string>indice[n2];
        for(int j=1;j<=n2;j++){
            int n3;//numero de nomes que cada programa tem
            cin >> n3;
            for(int k=0;k<n3;k++){
                int pos;
                cin >> input;
                for(int l=0;l<input.length();l++){
                    input[l]=tolower(input[l]);
                }
                input[0]=toupper(input[0]);
                int letra=int(input[0])-64;//dessa forma a letra A vai ser 1 e assim por diante
                indice[j-1].push_back(input);
                cap[j][letra+26]=1;//os primeiros 26 nodos sao os programas e o resto sao as letras
                cap[0][j]=1;//posicao 0 eh o nodo artificial de comeco
                cap[letra+26][54]=1;// posicao 54 eh o nodo articfial de fim
            }
        }
        fordFulkerson( 55, 0, 54 );
        cout << "Case #" << i+1 << ":\n";
        for(int j=27;j<54;j++){//percorro cada letra
            for(int k=1;k<=n2;k++){//percorro cada programa
                if(fnet[k][j]-fnet[j][k]>0){
                    for(int l=0;l<indice[k-1].size();l++){
                        if(indice[k-1][l][0]==char(j-26+64))//se a primeira letra da palavra eh igual a sigla entao essa eh a palavra
                            cout << indice[k-1][l] << endl;
                    }
                }
            }
        }
        memset( cap, 0, sizeof( cap ) );
    }
    return 0;
}