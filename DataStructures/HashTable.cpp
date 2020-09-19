#include <iostream>
#include <list>
#include <vector>
#include <time.h>

using namespace std;

typedef vector<list<int> > ht;

int hashFunction(int value, int n){                             //  Determinar la llave
    return value % n;
}

void insertItem(ht &A, int value){                              //  Agregar un valor nuevo a la tabla
    int n = A.size();
    int index = hashFunction(value, n);                         //  Determinar su llave
    A[index].push_back(value);                                  //  Agregarlo a la lista
}

void deleteItem(ht& A, int value){                              //  Eliminar la llave
    int n = A.size();
    int index = hashFunction(value, n);
    
    list <int> :: iterator i; 
    for(i = A[index].begin(); i != A[index].end(); ++i){        //  Buscar el elemento
        if(*i == value)
            break;
    }

    if(i != A[index].end())                                     //  Si el elemento exite
        A[index].erase(i);
}

bool searchItem(ht &A, int value){                              //  Revisar si un dato existe
    int n = A.size();
    int index = hashFunction(value, n);

    list <int> :: iterator i; 
    for(i = A[index].begin(); i != A[index].end(); ++i){        //  Buscar el dato
        if(*i == value)
            break;
    }
    
    if(i != A[index].end())                                     //  Si existe el dato
        return 1;

    return 0;
}

void displayHashTable(ht &A){                                   //  Mostrar la tabla
    int n = A.size();
    for(int i = 0; i < n; ++i){
        cout << i << ":";
        for(auto x: A[i]){
            cout << " -> " << x ;
        }
        cout << "\n";
    }
}

int main(){
    
    int n = 10;                                 //  Tamaño de la tabla
    vector<list<int> > hash(n);                 //  Tabla Hash

    srand (time(NULL));

    for(int i = 0; i < 15; ++i){                
        insertItem(hash, rand() % 100);    
    }
    
    displayHashTable(hash);

    int value;
    for(int i = 0; i < 5; ++i){
        cin >> value;
        deleteItem(hash, value);
        displayHashTable(hash); 
    }

    return 0;
}