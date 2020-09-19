#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > graph;
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

void DFS(graph &A, vbool &visited, int at){
    if(visited[at])                                     //  Si el nodo ha sido visitado
        return;
    visited[at] = true;                                 //  Marcar el nodo visitado nuevo

    cout << at << " ";

    for(auto next: A[at]){                              //  Visitar los nodos vecinos
        DFS(A, visited, next);
    }

}

void startDFS(graph &A, int n, int m){                  //  Iniciar DFS
    vector<bool> visited(n);                            //  Vector para nodos visitados
    int start_node = 0;                                 //  Nodo inicial
    DFS(A, visited, start_node);                        //  Iniciar
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
    startDFS(A, n, m);

    return 0;
}