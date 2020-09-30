#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<char> > graph;
typedef vector<vector<bool> > mbool;
typedef pair<int, int> pint;
typedef queue<pair<int, int> > qpint;

void initVisited(mbool &A, int n, int m){       //  Iniciar la matriz de visitados
    for(int i = 0; i < n; ++i){
        A[i] = vector<bool> (m, 0);
    }
}

void exploreNeighbour(graph &M, pint &A, mbool &V, qpint &Q, int &layer, int n, int m){
    vector<int> dx = {-1, 1, 0, 0};             //  Direcciones Norte, Sur, Este u Oeste
    vector<int> dy = {0, 0, 1, -1};

    for(int i = 0; i < 4; ++i){
        int xx = A.first + dx[i];               //  Moverse en los nodos vecinos
        int yy = A.second + dy[i];

        if(xx < 0 || yy < 0) continue;          //  Eliminar nodos no posibles de visitar
        if(xx >= n || yy >= m) continue;        
        if(V[xx][yy]) continue;                 //  Nodos visitados
        if(M[xx][yy] == '#') continue;          //  Nodos que no se pueden visitar

        Q.push(make_pair(xx, yy));              //  Nodos vecinos
        V[xx][yy] = true;                       //  Marcar nodos visitados
        layer++;                                //  Marcar nodos vistados para contar movimientos
    }
}

int ShortestPath(graph &A, int n, int m){
    pair<int, int> start = make_pair(0, 0);                 //  Posición inicial
    queue<pair<int, int> > queueXY;                         //  Cola de posición

    int move_count = 0;                         //  Movimientos para alcanzar el final
    int left_layer = 1;                         //  Variables de control
    int next_layer = 0;

    bool reached_end = false;                   //  Comprobar si llegamos al objetivo
    vector<vector<bool> > visited(n);
    initVisited(visited, n, m);

    queueXY.push(start);                        //  Iniciar proceso desde el nodo inicial
    visited[start.first][start.second] = true;  //  Marcarlo como visitado

    while(!queueXY.empty()){                                //  Mientras se necesitan explorar vecinos
        pair<int, int> actualNode = queueXY.front();        //  Nodo a explorar
        queueXY.pop();                                      //  Eliminar nodo actual visitado

        if(A[actualNode.first][actualNode.second] == 'E'){  //  Si alcanzamos el objetivo
            reached_end = true;
            break;
        }
        //  Explorar vecidad del nodo actual
        exploreNeighbour(A, actualNode, visited, queueXY, next_layer, n, m);
        left_layer--;

        if(left_layer == 0){                    //  Comprobar movimientos
            left_layer = next_layer;
            next_layer = 0;
            move_count++;
        }
    }
    if(reached_end)                             //  Regresar el número de nodos de distancia
        return move_count;
    return -1;                                  //  No se puede llegar al final
}

void display(graph &A, int n, int m){           //  Mostrar el grafo 
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n;    int m;                                              
    cin >> n >> m;
    vector<vector<char> > A(n);     

    for(int i = 0; i < n; ++i){
        A[i] = vector<char> (m);
        for(int j = 0; j < m; ++j){
            cin >> A[i][j];
        }
    }

    display(A, n, m);

    cout <<  ShortestPath(A, n, m);

    return 0;
}

    /*  Ejemplos de uso
        10 15
        S . . E # . . # # . # . . . .
        . . . # # # . . # . # # # . .
        # . . . . . . . # . . . # . #
        # # . . . # . . # . . # # . #
        . # # . . # # . . . # # # . .
        . . # . . . # . . . # # . . .
        . . . . . . . . # # # . . . .
        # # # . . . # # . . . . # # #
        # . # # # . . # . # . # . # .
        . . . . . . . . . # . # . . .
    */                    
