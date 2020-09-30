#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<vector<int> > graph;
typedef vector<int> vint;
typedef vector<bool> vbool;

void connectGraph(int x, int y, graph &A){
    A[x].push_back(y);                                  //  Conectar nodos
    A[y].push_back(x);
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

bool dfs(int at, int p, set<int> &A, graph &G){
    A.insert(at);                   //  Marcar como visitado los nodos anteriores

    for(auto x: G[at]){             //  Visitar la vecidad de nodos
        if(p == x)
            continue;
        if(A.count(x))
            return true;
        if(dfs(x, at, A, G))
            return true;
    }
    
    return false;
}

bool hasCycleUsingDFS(graph &G){
    set<int> visited;
    int n = G.size();
    int p = 0;

    for(int i = 0; i < n; ++i){         //  Recorrer todos los nodos
        if(visited.size() == n)         //  Si ya recorrimos todos los nodos
            break;
        if(visited.count(i))            //  Si ya pasamos por ese nodo
            continue;
        for(auto x: G[i]){              //  Hacer el recorrido
            if(x == p)
                continue;
            if(dfs(x, p, visited, G))
                return true;
        }
        p = i;
    }

    return false;
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

    cout << hasCycleUsingDFS(A) << "\n";

    return 0;
}

    // Ejemplo de entrada
    // 9 8
    // 0 1
    // 1 4
    // 4 5
    // 1 3
    // 1 2
    // 2 3
    // 0 6
    // 8 7