#include <iostream>
#include <cmath>
using namespace std;

/* Definición de la estructura de un nodo */
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

/* Función para insertar un nuevo nodo en el árbol */
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

/* Función para encontrar el nodo más cercano a un valor dado */
Node* findClosestNode(Node* root, int value) {
    Node* closest = root;
    int minDistance = abs(root->data - value);
    while (root != nullptr) {
        if (abs(root->data - value) < minDistance) {
            minDistance = abs(root->data - value);
            closest = root;
        }
        if (root->data == value) {
            return root;
        }
        else if (value < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return closest;
}

/* Función principal */
int main() {
    /* Crear un árbol binario */
    Node* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    /* Encontrar el nodo más cercano a un valor dado */
    int value = 25;
    Node* closestNode = findClosestNode(root, value);

    /* Imprimir el nodo más cercano */
    cout << "El nodo más cercano a " << value << " es " << closestNode->data << endl;

    return 0;
}
