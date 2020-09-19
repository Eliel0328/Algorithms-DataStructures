#include <iostream>
#include <vector>
#include <queue>

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

void BFS(graph &A, vbool &visited, int at){     //  Inicializar BFS
    queue<int> q;                               //  Cola para nodos visitados
    q.push(at);
    visited[at] = true;                         //  Marcar como nodo visitado el nodo incial

    while(!q.empty()){                          //  Mientras sigan existiendo nodos por revisar
        int node = q.front();                   //  El dato que ya hemos visitado y sera eliminado
        cout << node <<  " ";
        q.pop();
        
        for(auto next: A[node]){                //  Visitar a sus vecinos y marcalo como tal
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void startBFS(graph &A, int n, int m){                  //  Iniciar BFS
    vector<bool> visited(n);                            //  Vector para nodos visitados
    int start_node = 0;                                 //  Nodo inicial
    
    BFS(A, visited, start_node);                        //  Iniciar
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