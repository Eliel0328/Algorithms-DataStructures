//  El algoritmo no permite ciclos
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > graph;
typedef vector<int> vint;
typedef vector<bool> vbool;

void connectGraph(int x, int y, graph &A){
    A[x].push_back(y);                                  //  Conectar nodos
}

void displayGraph(graph &A, int n){                     //  Mostrar el contenido del grafo
    for(int i = 0; i < n; ++i){
        cout << i <<":[ ";
        int m = A[i].size();
        for(int j = 0; j < m; ++j){
            cout << A[i][j] << " ";
        }
        cout << "]\n";
    }
}

void dfs(int at, vbool &V, vint &vnodes, graph &A){     //  Hacer el recorrido 
    V[at] = true;                           //  Marcar nodo como visitado

    for(auto edge: A[at])                   //  Recorrer nodos vecinos
        if(!V[edge])            
            dfs(edge, V, vnodes, A);
        
    vnodes.push_back(at);                   //  Marcar nodos visitados
}

void topSort(graph &A, int n){
    vector<bool> V(n, 0);           
    vector<int> ordering(n, 0);
    int i = n - 1;

    for(int at = 0; at < n; ++at){              //  Recorrer nodos del grafo
        if(!V[at]){
            vector<int> vnodes;                 //  Nodos vecinos
            dfs(at, V, vnodes, A);
            for(auto x: vnodes){                //  Nodos visitados
                ordering[i] = x;                //  Ordenar los nodos visitados
                --i;
            }
        }
    }

    for(auto x: ordering){                      //  Mostrar el orden
        cout << x << " ";
    }

}

int main(){
    int n;  int m;   
    cin >> n >> m;                                           
    vector<vector<int> > A(n);  

    int a; int b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        connectGraph(a, b, A);                              
    }

    displayGraph(A, n);
    topSort(A, n);
    
    return 0;
}

    // 13 18 Ejemplo
    // 0 3
    // 1 3
    // 2 1
    // 2 0
    // 3 7
    // 3 6
    // 4 0
    // 4 3
    // 4 5
    // 6 8
    // 7 8
    // 7 9
    // 5 10
    // 5 9
    // 9 12
    // 9 11
    // 8 11
    // 10 9