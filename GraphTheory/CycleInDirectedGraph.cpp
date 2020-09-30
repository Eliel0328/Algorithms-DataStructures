#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

typedef vector<vector<int> > graph;
typedef vector<int> vint;
typedef vector<bool> vbool;
typedef stack<int> sint;

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

void moveVertex(int vertex, set<int> &A, set<int> &B){          //  Actualizar conjuntos visitados
    A.erase(vertex);
    B.insert(vertex);
}

bool dfs(int at, set<int> &A, set<int> &B, set<int> &C, graph &G){
    moveVertex(at, A, B);               //  Actualizar

    for(auto x: G[at]){                 //  Recorrer vecindad
        if(C.count(x))
            continue;
        if(B.count(x))                  //  Si ya hemos pasado por ahi
            return true;
        if(dfs(x, A, B, C, G))
            return true;
    }

    moveVertex(at, B, C);               //  Actualizar 
    return false;
}

bool hasCycle(graph &A){
    set<int> white;                     //  Sin visitar
    set<int> gray;                      //  Estamos actualmente sobre el
    set<int> black;                     //  Ya fue visitado
    int n = A.size();

    for(int i = 0; i < n; ++i){         //  Inicializar sin visitar
        white.insert(i);
    }

    set <int> :: iterator itr;          //  Iterador para las actualizaciones
    while(!white.empty()){
        itr = white.begin();
        if(dfs(*itr, white, gray, black, A))        //  Hacer el recorrido
            return true;    
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
    
    cout << hasCycle(A) << "\n";

    return 0;
}

    // Ejemplo de entrada
    // 13 18 
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
    
