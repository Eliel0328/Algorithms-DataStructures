#include <iostream>

using namespace std;

struct Node{                                        //  Nodo lista doblemente enlazada 
    int data;
    struct Node* next;
    struct Node* prev;
};

    //  Insertar dato al inicio de la lista
void insertFront(int newData, struct Node** head, struct Node** tail){
    struct Node* newNode = new Node();              //  Nuevo nodo
    newNode -> data = newData;                      //  Nuevos datos
    newNode -> prev = NULL;                         //  Nada antes del inicio
    newNode -> next = (*head);                      //  Nuevo inicio

    if((*head) == NULL)                             //  Si es el primer dato 
        (*tail) = newNode;                          
    else
        (*head) -> prev = newNode;                  //  Actualizar datos de la vieja cabecera
    (*head) = newNode;
}
    //  Insertar datos al final de la lista
void insertEnd(int newData, struct Node** head, struct Node** tail){
    if((*head) == NULL){                            //  En caso de ser el primer dato
        insertFront(newData, head, tail);
        return;
    }
    
    struct Node* newNode = new Node();              //  Nuevo nodo
    newNode -> data = newData;                      //  Nuevos datos
    newNode -> next = NULL;
    newNode -> prev = (*tail);                      //  Actualizar final de la lista
    (*tail) -> next = newNode;
    (*tail) = newNode;
}

void deleteFront(struct Node** head){               //  Eliminar nodo inicial
    if((*head) == NULL)
        return;
    
    struct Node* temp = (*head);                    //  Nodo a eliminar
    (*head) = (*head) -> next;                      //  Actualizar nodos
    (*head) -> prev = NULL;
    delete temp;
}

void deleteEnd(struct Node** tail){                 //  Eliminar nodo final
    if((*tail) == NULL)
        return;
    
    struct Node* temp = (*tail);                    //  Nodo a eliminar
    (*tail) = (*tail) -> prev;                      //  Actualizar nodos
    (*tail) -> next = NULL;
    delete temp;
}

void deleteData(int data, struct Node** head, struct Node** tail){
    if((*head) == NULL)                             //  Si la lista esta vacia
        return;

    struct Node* temp = (*head);                    //  El nodo que recorre la lista
    while(temp != NULL && temp -> data != data)     //  Buscar el dato
        temp = temp -> next;
    
    if(temp -> data = data){                        //  Si existe el dato
        if(temp == (*head))                         //  Si es el inicio
            deleteFront(head);
        else if(temp == (*tail))                    //  Si es el final
            deleteEnd(tail);
        else{                                       //  Otro caso
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            delete temp;
        }
    }
}

void deleteAtPosition(int index, struct Node** head, struct Node** tail){
    if((*head) == NULL)                             //  Si la lista esta vacia
        return;

    if(index == 0)                                  //  Si es el inicio
        deleteFront(head);

    int count = 0;                                  //  Contador para la posicion
    struct Node* temp = (*head);
    while(temp != NULL && count != index){          //  Buscar la posicion
        temp = temp -> next;
        count++;
    }
        
    if(count == index){                             //  Si la posicion existe
        if(temp == (*tail))                         //  Si es el ultimo nodo
            deleteEnd(tail);
        else{                                       //  Si es un nodo intermedio
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            delete temp;
        }
    }
}

bool findData(int data, struct Node* node){         //  Buscar un dato si existe
    if(node == NULL)                                //  Si la lista esta vacia
        return 0;
    
    while(node != NULL && node -> data != data){    //  Buscar el dato
        node = node -> next;
    }     
        
    if(node != NULL)                                //  Si lo encontramos
        return 1;
    return 0;                                       //  Si no esta
}

int dataPosition(int data, struct Node* node){      //  La posicion de un dato
    if(node == NULL)                                //  Si la lista esta vacia
        return -1;
    
    int count = 0;                                 //  Contador para la posicion
    while(node != NULL && node -> data != data){    //  Buscar la posicion del dato
        node = node -> next;
        count++;
    }

    if(node != NULL)                                //  Si el dato existe
        return count;                               //  Retornar la posicion
    return -1;                                      //  No esta en la lista
}

int size(struct Node* node){
    if(node == NULL)                                //  Si la lista esta vacia
        return -1;
    
    int count = 0;                                 //  Contador para la lista
    while(node != NULL){                           
        node = node -> next;
        count++;
    }

    return count;
}

void display(struct Node* node){ 
    while(node != NULL){
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << "\n";
}

int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    insertFront(5, &head, &tail);
    insertFront(9, &head, &tail);
    insertFront(4, &head, &tail);
    insertFront(3, &head, &tail);

    insertEnd(4, &head, &tail);
    insertEnd(3, &head, &tail);
    
    display(head);
    cout << findData(8, head) << "\n";
    cout << dataPosition(3, head) << "\n";
    cout << size(head) << "\n";
    display(head);


    return 0;
}
