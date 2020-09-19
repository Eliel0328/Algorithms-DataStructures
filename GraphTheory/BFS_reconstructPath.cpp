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

void BFS(graph &A, vbool &visited, vint &path, int at){
    queue<int> q;
    q.push(at);
    visited[at] = true;

    while(!q.empty()){
        int node = q.front();
        cout << node <<  " ";
        q.pop();
        for(auto next: A[node]){
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                path[next] = node;
            }
        }
    }
}

void reconstructPath(vint &prev, int start, int end){
    vector<int> path;
    int i = 0;  int at;

    for(at = end; at != start; at = prev[at]){
        if(i < prev.size()){
            ++i;
            path.push_back(at);
        }
        else
            break;
    }

    if(prev[at] == start){
        path.push_back(at);
        reverse(path.begin(), path.end());
        for(auto x: path)
            cout << x << " ";
    }

}

void startBFS(graph &A, int n, int m){                  //  Iniciar BFS
    vector<bool> visited(n);                            //  Vector para nodos visitados
    vector<int> path(n);                                //  Vector para reconstruir ruta
    int start_node = 0;                                 //  Nodo inicial
    int end_node = 5;                                  //  Nodo final
    
    BFS(A, visited, path, start_node);                  //  Iniciar
    cout << "\n";
    reconstructPath(path, start_node, end_node);
}

int main(){
    int n;                                              //  Tamaño del grafo
    int m;                                              //  Número de vertices
    vector<vector<int> > A(n);                          //  Inicializar lista de adyacencia

    cin >> n >> m;
    int a; int b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        connectGraph(a, b, A);                              
    }

    displayGraph(A, n);
    startBFS(A, n, m);

    return 0;
}