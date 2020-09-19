#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef vector<int> vi;

void push(vi &PQ, int &pf, int data){               //  Ingresar un dato a la PQ
    PQ[pf] = data;                                  //  Dato en posicion final

    int j = pf;                                     //  Apuntador padre
    int i = pf;                                     //  Apuntador actual

    while(j > 0){                                   //  Mientras no pase el nodo incial
        if(j % 2 == 0){                             //  Si el nodo es un hijo derecho
            i = j;  j = floor((j - 1) / 2);         //  Ir al nodo padre
            if(j < 0 || PQ[j] > PQ[i])              //  Si la posicion es correcta
                break;
            else
                swap(PQ[j], PQ[i]);                 //  Realizar el cambio de datos
        }
        else{   
            i = j;  j = floor(j / 2);               //  Ir al nodo padre
            if(j < 0 || PQ[j] > PQ[i])              //  Si la posicion es correcta
                break;
            else
                swap(PQ[j], PQ[i]);                 //  Realizar el cambio
        }
    }
    
    pf++;                                           //  Siguiente nodo final
}

void pop(vi &PQ, int &pf){                          //  Eliminar el primer nodo
    if(pf < 0)                                      //  Si no tenemos nada en la PQ
        return;

    --pf;                                           //  Intercambiar el nodo 0 por el ultimo 
    swap(PQ[0], PQ[pf]);                            //nodo y reestructurar la PQ
    
    int j = 0;                              //  Apuntador hijo derecho
    int i = 0;                              //  Apuntador hijo izquierdo
    int k = 0;                              //  Apuntador actual

    while(k < pf){                          //  Mientras no hemos llegado al final de la PQ
        i = (2*k) + 1;                      //  Ir al hijo izquierdo
        j = (2*k) + 2;                      //  Ir al hijo derecho
        
        if(j < pf && PQ[j] > PQ[i]){        //  Si no el final y el hijo derecho es mayor al izquierdo
            if(PQ[k] > PQ[j])               //  Si la posicion es correcta
                break;
            else{
                swap(PQ[j], PQ[k]);         //  Ajustar la PQ
                k = j;                      //  Posicion actual
            }
        }else if(i < pf){                   //  Si no es el final y el hijo izquierdo es mayor o igual al derecho
            if(PQ[k] > PQ[i])               //  Si la posicion es correcta
                break;          
            else{
                swap(PQ[i], PQ[k]);         //  Ajustar la PQ
                k = i;                      //  Posicion actual
            }
        }else{
            break;                          //  Si la PQ esta actualizada
        }
    }
}

int top(vi &PQ, int pf){                    //  Retornar el primer dato     
    if(PQ[0] != NULL && pf != 0)            //  Si el vector esta vacio
        return -1;
    return PQ[0];                           //  El primer dato o mayor de la PQ
}

int size(int pf){                           //  El tamaño de la PQ
    return pf;
}

void display(vi &PQ, int pf){               //  Imprimir los datos de la PQ
    for(int i = 0; i < pf; ++i){                
        cout << PQ[i] << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> PQ(100);
    int pointerFinal = 0;

    push(PQ, pointerFinal, 5);
    push(PQ, pointerFinal, 3);
    push(PQ, pointerFinal, 12);
    push(PQ, pointerFinal, 14);
    push(PQ, pointerFinal, 18);
    push(PQ, pointerFinal, 15);
    push(PQ, pointerFinal, 6);
    push(PQ, pointerFinal, 4);
    push(PQ, pointerFinal, 17);
    push(PQ, pointerFinal, 9);
    display(PQ, pointerFinal);
    cout << size(pointerFinal) << "\n";
    pop(PQ, pointerFinal);
    display(PQ, pointerFinal);
    cout << size(pointerFinal) << "\n";
    return 0;
}