//  Fenwick tree, se esta indexando desde 1 aunque existe la casilla 0
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vint;           

void display(vint &A){                      //  Mostrar los elementos del vector
    int n = A.size();
    for(int i = 1; i < n; ++i){
        cout << A[i] << " ";
    }cout << "\n";
}

int lsb(int n){                             //  Obtener el bit menos significativo
    return n & -n;
}

int getSum(int i, vint &A){                 //  Obtener la suma de un rango iniciando desde 0
    int sum = 0;    ++i;                    //  Variables para la suma y el recorrido

    while (i > 0){                          //  Recorrer el vector
        sum += A[i];                        //  Acumular
        i -= lsb(i);                
    } 

    return sum;                             //  Retornar el total de la suma
}

int rangeSum(int i, int j, vint &A){        //  Obtener la suma de un rango que no inicie en 0
    return getSum(j, A) - getSum(i-1, A);   
}

void updateRange(vint &A, vint &B, int i, int n, int value){    //  Actualizar datos en ambos vectores
    A[++i] += value;                        //  Actualizar vector original, recordando que se indexo desde 0
    
    while(i <= n){                          //  Recorrer el arreglo de los precalculos
        B[i] += value;                      //  Actualizar datos
        i += lsb(i);
    }
}

void constructFenwickTree(vint &original, vint &prefix, int n){     //  Armar el vector con la presuma
    if(!(original.size() == prefix.size()))     //  Error
        return;
    
    prefix = original;

    for(int i = 1; i < n; ++i){                 //  Recorrer el vector original
        int j = i + lsb(i);
        if(j < n){                              
            prefix[j] = prefix[j] + prefix[i];  //  Hacer el precalculo
        }
    }
        
}

int main(){

    /*
    12
    2 1 1 3 2 3 4 5 6 7 8 9
    */

    int n; cin >> n;
    vector<int> nums(n + 1);
    vector<int> prefixNums(n + 1);

    for(int i = 1; i <= n ; ++i){
        cin >> nums[i];
    }

    constructFenwickTree(nums, prefixNums, n + 1);
    display(nums);
    display(prefixNums);
    cout << getSum(5, prefixNums) << " "<< rangeSum(1, 5, prefixNums) << "\n";
    updateRange(nums, prefixNums, 3, n+1, 6);
    display(nums);
    display(prefixNums);
    cout << getSum(5, prefixNums) << " "<< rangeSum(1, 5, prefixNums) << "\n";
    
    
    

    return 0;
}