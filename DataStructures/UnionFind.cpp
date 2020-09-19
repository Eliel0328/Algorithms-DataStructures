#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

void MakeSet(vi &padre, vi &rango, int n){  //  Método de inicialización
    for(int i = 0 ; i < n ; ++i){
        padre[i] = i;                     //  Inicialmente el padre de cada vértice es el mismo vértice
        rango[i] = 0;                     //  Altura o rango de cada vértice es 0
    }
}

int Find(vi &padre, int x){                 //  Método para encontrar la raiz del vértice actual X
    if(x == padre[x]){                      //  Si estoy en la raiz
        return x;                           //  Retorno la raiz
    }
    //  De otro modo busco el padre del vértice actual, hasta llegar a la raiz
    else return padre[x] = Find(padre, padre[x]);     //  Compresion de caminos
}

void Union(vi &padre, vi &rango, int x, int y){   //  Método para unir 2 componentes conexas usando sus alturas (rangos)
    int xRoot = Find(padre, x);                         //  Obtengo la raiz de la componente del vértice X
    int yRoot = Find(padre, y);                         //  Obtengo la raiz de la componente del vértice Y
    if(rango[xRoot] > rango[yRoot]){                    //  en este caso la altura de la componente del vértice X es
        padre[yRoot] = xRoot;                           //  mayor que la altura de la componente del vértice Y.
    }                                                   //  el padre de ambas componentes será el de mayor altura
    else{                                   // en este caso la altura de la componente del vértice Y es mayor o igual que la de X
        padre[xRoot] = yRoot;               // el padre de ambas componentes será el de mayor altura
        if(rango[xRoot] == rango[yRoot]){   //  si poseen la misma altura
            rango[yRoot]++;                 // incremento el rango de la nueva raíz
        }
    }
}

int getNumberConnectedComponents(vi &padre, vi &rango, int n){//  Obtener el numero de componentes conexas luego de realizar las conexiones respectivas
    int numComponentes = 0;
    for( int i = 0 ; i < n ; ++i ){
        if(padre[i] == i){                  //  Si el padre del vértice i es el mismo vértice entonces es raíz podemos usamos find para el mismo proposito y para que se realice compresion de caminos
            rango[numComponentes++] = i;    //  almaceno la raiz de cada nueva componente
        }
    }
    return numComponentes;
}

bool sameComponent(vi & padre, int x , int y){              //  Determina si 2 vértices estan o no en la misma componente conexa
    if( Find(padre, x) == Find(padre, y) ) return true;     //  si poseen la misma raíz
    return false;
}

void display(vi &padre, vi &rango, int n){  //  Mostrar datos
    for( int i = 0 ; i < n ; ++i ){
        cout << i << ":(" << padre[i] << ", " << rango[i] << ") ";                
    }
    cout << "\n";
}

int main(){
    vector<int> padre(10);
    vector<int> rango(10);

    MakeSet(padre, rango, 10);
    display(padre, rango, 10);
    Union(padre, rango, 2, 0);
    display(padre, rango, 10);
    Union(padre, rango, 7, 2);
    display(padre, rango, 10);
    Union(padre, rango, 3, 1);
    display(padre, rango, 10);
    Union(padre, rango, 3, 7);
    display(padre, rango, 10);
    Union(padre, rango, 6, 4);
    display(padre, rango, 10);
    Union(padre, rango, 8, 4);
    cout << getNumberConnectedComponents(padre, rango, 10) << "\n";
    display(padre, rango, 10);
    Union(padre, rango, 4, 5);
    display(padre, rango, 10);
    Union(padre, rango, 3, 8);
    cout << getNumberConnectedComponents(padre, rango, 10) << "\n";
    display(padre, rango, 10);
    cout << sameComponent(padre, 9, 0) << "\n";
    cout << sameComponent(padre, 7, 0) << "\n";

    return 0;
} 