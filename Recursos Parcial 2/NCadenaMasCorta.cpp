#include <iostream>
#include <algorithm>

using namespace std;

// Definición de un nodo del árbol binario
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Función recursiva para encontrar la rama más corta del árbol binario
int shortestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // Recursivamente encontrar la rama más corta del subárbol izquierdo y derecho
    int leftPath = shortestPath(root->left);
    int rightPath = shortestPath(root->right);

    // Devolver la longitud de la rama más corta del subárbol izquierdo y derecho
    return 1 + min(leftPath, rightPath);
}

int main() {
    // Ejemplo de un árbol binario no balanceado
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(6);

    // Encontrar la longitud de la rama más corta del árbol binario
    int shortest = shortestPath(root);

    // Imprimir la longitud de la rama más corta del árbol binario
    cout << "La longitud de la rama más corta del árbol binario es: " << shortest << endl;

    return 0;
}
