#include <iostream>
#include <algorithm>

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

/* Función para encontrar la altura de un árbol */
int findHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

/* Función para encontrar el camino más largo en el árbol */
int findLongestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    int leftLongestPath = findLongestPath(root->left);
    int rightLongestPath = findLongestPath(root->right);
    return max(leftHeight + rightHeight, max(leftLongestPath, rightLongestPath));
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

    /* Encontrar el camino más largo en el árbol */
    int longestPath = findLongestPath(root);

    /* Imprimir la longitud del camino más largo */
    cout << "La longitud del camino más largo en el árbol es: " << longestPath << endl;

    return 0;
}