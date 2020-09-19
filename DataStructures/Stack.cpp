#include <iostream>

using namespace std;

struct Node{                                            //  Nodo de la cola
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(int data, struct Node** head, struct Node** tail){    //  Ingresar un nuevo nodo
    struct Node* newNode = new Node();                  //  Nodo nuevo
    newNode -> data = data;                             //  Nuevos datos
    newNode -> next = NULL;                             
    newNode -> prev = (*head);

    if((*head) == NULL){                                //  Si es el primer dato
        (*tail) = newNode;
    }else{                                              //  Si ya existen datos 
        (*head) -> next = newNode;
    }
    (*head) = newNode;                                  //  Actualizar el ultimo nodo
}

void pop(struct Node** head){                           //  Eliminar un nodo 
    if((*head) == NULL)                                 //  Si la cola esta vacia
        return;

    struct Node* temp = (*head);                        //  El nodo a eliminar
    (*head) = (*head) -> prev;                          //  Actualizar el nodo inicial
    delete temp;   
}

int top(struct Node* head){                           //  Retornar el primer dato
    if(head == NULL)                                    //  Si la cola esta vacia
        return -1;
    return head -> data;
}

int size(struct Node* node){                            //  Calcular el numero de nodos de la cola
    if(node == NULL)                                    //  Si la cola esta vacia
        return -1;
    
    int count = 0;
    while (node != NULL){                               //  Contar el numero de nodos
        node =  node -> prev;
        count++;
    }

    return count;                                       //  Retornar el numero de nodo
}

bool findData(int data, struct Node* node){             //  Ver si existe un dato
    if(node == NULL)                                    //  Si la lista esta vacia
        return 0;
    
    while(node != NULL && node -> data != data)         //  Buscar el nodo
        node = node -> prev;
    
    if(node != NULL)                                    //  Si existe el dato
        return 1;
    return 0;
}

void display(struct Node* node){                        //  Imprimir la lista
    if(node == NULL)
        return;
    while(node != NULL){
        cout << node -> data << " ";
        node = node -> prev;
    }
    cout << "\n";
}

int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;

    push(2, &head, &tail);
    push(3, &head, &tail);
    push(8, &head, &tail);
    push(9, &head, &tail);
    push(4, &head, &tail);
    display(head);
    cout << top(head) << "\n";
    cout << size(head) << "\n";
    pop(&head);
    display(head);
    cout << findData(8, head) << "\n";
    cout << findData(5, head) << "\n";

    return 0;
}