#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* Definición de la estructura de un nodo */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Función para crear un nuevo nodo */
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Función para insertar un nuevo nodo en el árbol */
struct node* insertNode(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

/* Función para encontrar el nodo con el valor mínimo */
struct node* findMinNode(struct node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findMinNode(root->left);
}

/* Función para encontrar el nodo con el valor máximo */
struct node* findMaxNode(struct node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findMaxNode(root->right);
}

/* Función principal */
int main() {
    /* Crear un árbol binario */
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    /* Encontrar el nodo con el valor mínimo */
    struct node* minNode = findMinNode(root);
    printf("Valor mínimo: %d\n", minNode->data);

    /* Encontrar el nodo con el valor máximo */
    struct node* maxNode = findMaxNode(root);
    printf("Valor máximo: %d\n", maxNode->data);

    return 0;
}
