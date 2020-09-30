#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > graph;
typedef vector<bool> vbool;
typedef vector<int> vint;

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

void BFS(graph &A, vbool &visited, vint &path, int at){     //  Iniciar recorrido BFS   
    queue<int> q;                                       //  Cola para recorrido
    q.push(at);
    visited[at] = true;                 

    while(!q.empty()){                                  //  Mientras no recorramos todo el grafo
        int node = q.front();
        cout << node <<  " ";
        q.pop();
        for(auto next: A[node]){                        //  Visitar vecinos
            if(!visited[next]){
                q.push(next);
                visited[next] = true;                   //  Marcar como visitados
                path[next] = node;
            }
        }
    }
}

void reconstructPath(vint &prev, int start, int end){       //  Reconstruir el camino
    vector<int> path;
    int i = 0;  int at;

    for(at = end; at != start; at = prev[at]){              //  Recorrer el posible camino
        if(i < prev.size()){                                //  Abortar si no se encuentra
            ++i;
            path.push_back(at);
        }
        else
            break;
    }

    if(prev[at] == start){                                  //  Comprobar si llegamos al inicio
        path.push_back(at);
        reverse(path.begin(), path.end());          
        for(auto x: path)                                   //  Mostrar el recorrido
            cout << x << " ";
    }

}

void startBFS(graph &A, int n, int m){                  //  Iniciar BFS
    vector<bool> visited(n);                            //  Vector para nodos visitados
    vector<int> path(n);                                //  Vector para reconstruir ruta
    int start_node = 0;                                 //  Nodo inicial
    int end_node = 5;                                   //  Nodo final
    
    BFS(A, visited, path, start_node);                  //  Iniciar
    cout << "\n";
    reconstructPath(path, start_node, end_node);
}

int main(){
    int n;                                              //  Tamaño del grafo
    int m;                                              //  Número de vertices
    cin >> n >> m;
    vector<vector<int> > A(n);                          //  Inicializar lista de adyacencia

    int a; int b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        connectGraph(a, b, A);                              
    }

    displayGraph(A, n);
    startBFS(A, n, m);

    return 0;
}