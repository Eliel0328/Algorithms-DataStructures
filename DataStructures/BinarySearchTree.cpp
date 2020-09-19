#include <iostream>

using namespace std;

struct Node{                    //  Estructura de un nodo
    int data;
    struct Node* right;
    struct Node* left;
};

Node* insert(struct Node* root, int data){      //  Insertar un nodo nuevo 
    if(root == NULL){                           //  Posición correcta
        struct Node* newNode = new Node();      //  
        newNode -> data = data;
        newNode -> right = NULL;
        newNode -> left = NULL;
        return newNode;                         //  Nuevo nodo
    }
    else if(data > root -> data){               //  Si el dato es mayor lo colocamos a la derecha
        root -> right = insert(root -> right, data);
    }
    else if(data < root -> data){               //  Si el dato es menor lo colocamos a la izquierda
        root -> left = insert(root->left, data);
    }
    return root;
}

Node* findMin(struct Node* node){           //  Buscar el nodo menor
    if(node == NULL)                        //  Vacio
        return NULL;
    else if(node -> left == NULL)           //  Ya no quedan más datos
        return node;                        //  Encontramos el menor dato
    else
        return findMin(node->left);         //  Seguir buscando el dato menor
}

Node* findMax(struct Node* node){           //  Buscar el nodo mayor
    if(node == NULL)                        //  Vacio
        return NULL;
    else if(node -> right == NULL)          //  Ya no quedan más datos 
        return node;                        //  Encontramos el nodo mayor
    else
        return findMin(node->right);        //  Seguir buscando el nodo mayor
}

Node* remove(struct Node* node, int data){  //  Eliminar un nodo especifico
    if(node == NULL)                                        //  Vacio
        return NULL;
    else if(data < node->data)                              //  Si el dato es menor
        node->left = remove(node->left, data);              //  Buscamos a la izquierda
    else if(data > node->data)                              //  Si el dato es mayor
        node->right = remove(node->right, data);            //  Buscamos a la derecha
    else if(node->left && node->right){                     //  Cuando el nodo tiene ambos hijos
        struct Node* temp = findMin(node->right);           //  Nodo a eliminar/Buscar un nuevo nodo para esta posición
        node->data = temp->data;                            //  Actualizar los nodos
        node->right = remove(node->right, node->data);      //  Eliminar el nodo que duplicado
    }
    else{
        struct Node* temp = node;
        if(node->left == NULL)                              //  Si solo se tiene un hijo derecho
            node = node->right;
        else if(node->right == NULL)                        //  Si solo se tiene un hijo izquierdo
            node = node->left;
        
        delete temp;                                        //  Eliminar duplicado
    }
    return node;
}

void inorder(struct Node* node){            //  Imprimir los nodos
    if(node != NULL){
        inorder(node -> left);
        cout << node->data << " ";
        inorder(node -> right);
    }
}

void preorder(struct Node* node){            //  Imprimir los nodos
    if(node != NULL){
        cout << node->data << " ";
        inorder(node -> left);
        inorder(node -> right);
    }
}

void postorder(struct Node* node){            //  Imprimir los nodos
    if(node != NULL){
        inorder(node -> left);
        inorder(node -> right);
        cout << node->data << " ";
    }
}

int main(){
    struct Node* root = NULL;
    
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 9);
    insert(root, 7);
    insert(root, 18);
    insert(root, 15);
 
    inorder(root);  cout << "\n";
    remove(root, 4);
    inorder(root);  cout << "\n";
    remove(root, 4);
    inorder(root);  cout << "\n";
    remove(root, 5);
    inorder(root);  cout << "\n";
    remove(root, 1);
    inorder(root);  cout << "\n";
    remove(root, 18);
    inorder(root);  cout << "\n";


    return 0;
}