#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
typedef vector<int> vi;

void insertionSort(vi &a){          //  Ordenamiento similar a ordenar cartas en las manos
    int n = a.size();               //  Tamaño del arreglo
    int key;                        //  Auxiliar para recorrer los datos(De izquierda a derecha)
    int i;                          //  Indice para recorrer el arreglo
    for(int j = 1; j < n; ++j){     //  Para todos los elementos
        key = a[j];                 //  Guardamos el valor para recorrer los datos del arreglo
        i = j - 1;                  
        while(i >= 0 && a[i] > key){    //  Mientras exista un valor que pueda ser recorrido(un dato menor)
            a[i + 1] = a[i];            //  Recorremos los datos
            --i;
        }
        a[i + 1] = key;             //  Reasignamos el valor que se recorrio
    }
}


void display(vi & a){
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout <<"\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    srand (time(NULL));

    int n = 100;
    vector<int> muestra(n);

    for(int i = 0; i < n; ++i){
        muestra[i] = rand() % 1000;
    }

    display(muestra);
    insertionSort(muestra);
    display(muestra);

    return 0;
}