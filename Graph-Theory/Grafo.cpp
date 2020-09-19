//  Maneras de representar grafos no direccionados
//  Con algunas modificaciones podemos reprensetar grafos direccionados
//  Dependiendo de la ocasión determinamos el caso de uso

#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix;
typedef vector<pair<int, int> > vpint;

//                                  Edge lists

//  [ [0,1], [0,6], [0,8], [1,4], [1,6], [1,9], [2,4], [2,6], [3,4], [3,5], [3,8], 
//  [4,5], [4,9], [7,8], [7,9] ]

void displayEdgeList(vpint &A){                         //  Mostrar el contenido de la lista
    int n = A.size();
    cout << "[  ";
    for(int i = 0; i < n; ++i){
        cout << "[" << A[i].first << "," << A[i].second << "] ";
    }
    cout << "   ]\n";
}

//                                  Adjacency matrices

// [ [0, 1, 0, 0, 0, 0, 1, 0, 1, 0],
// [1, 0, 0, 0, 1, 0, 1, 0, 0, 1],
// [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
// [0, 0, 0, 0, 1, 1, 0, 0, 1, 0],
// [0, 1, 1, 1, 0, 1, 0, 0, 0, 1],
// [0, 0, 0, 1, 1, 0, 0, 0, 0, 0],
// [1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
// [0, 0, 0, 0, 0, 0, 0, 0, 1, 1],
// [1, 0, 0, 1, 0, 0, 0, 1, 0, 0],
// [0, 1, 0, 0, 1, 0, 0, 1, 0, 0] ]

void matrixCero(matrix &A, int n){                      //  Iniciar matriz
    for(int i = 0; i < n; ++i){
        A[i] = vector<int> (n);
        for(int j = 0; j < n; ++j){
            A[i][j] = 0;
        }
    }
}

void displayAdjacencyMatrix(matrix &A, int n){          //  Mostrar contenido de la matriz
    for(int i = 0; i < n; ++i){
        cout << i <<  ":[ ";
        for(int j = 0; j < n; ++j){
            cout << A[i][j] << " ";
        }
        cout << "]\n";
    }
}

//                                      Adjacency lists

// [ [1, 6, 8],
//   [0, 4, 6, 9],
//   [4, 6],
//   [4, 5, 8],
//   [1, 2, 3, 5, 9],
//   [3, 4],
//   [0, 1, 2],
//   [8, 9],
//   [0, 3, 7],
//   [1, 4, 7] ]

void displayAdjacencyList(matrix &A, int n){            //  Mostrar el contenido de la lista
    for(int i = 0; i < n; ++i){
        cout << i <<":[ ";
        int m = A[i].size();
        for(int j = 0; j < m; ++j){
            cout << A[i][j] << " ";
        }
        cout << "]\n";
    }
}

void connectGraph(int x, int y, vpint &A, matrix &B, matrix &C){
    A.push_back(make_pair(x, y));                       //  Conectar/Agregar a la lista de vertices

    B[x][y] = 1;                                        //  Relacionar nodos
    B[y][x] = 1;

    C[x].push_back(y);                                  //  Conectar nodos
    C[y].push_back(x);

}

int main(){

    int n = 10;         //  Numero de nodos
    
    vector<pair<int, int> > A;                     //  Inicializar lista de vertices
    
    vector<vector<int> > B(n);                        //  Inicializar matriz de adyacencia
    matrixCero(B, n);
    //displayAdjacencyMatrix(MatrixA, n);    

    vector<vector<int> > C(n);                         //  Inicializar lista de adyacencia

    connectGraph(0, 1, A, B, C);
    connectGraph(0, 6, A, B, C);
    connectGraph(0, 8, A, B, C);
    connectGraph(1, 4, A, B, C);
    connectGraph(1, 6, A, B, C);
    connectGraph(1, 9, A, B, C);
    connectGraph(2, 4, A, B, C);
    connectGraph(2, 6, A, B, C);
    connectGraph(3, 4, A, B, C);
    connectGraph(3, 5, A, B, C);
    connectGraph(3, 8, A, B, C);
    connectGraph(4, 5, A, B, C);
    connectGraph(4, 9, A, B, C);
    connectGraph(7, 8, A, B, C);
    connectGraph(7, 9, A, B, C);

    displayEdgeList(A);             cout << "\n";
    displayAdjacencyMatrix(B, n);   cout << "\n";
    displayAdjacencyList(C, n);     cout << "\n";


    return 0;
}