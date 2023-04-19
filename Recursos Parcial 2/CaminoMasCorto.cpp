#include <iostream>
#include <vector>
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

/* Función para buscar un nodo en el árbol */
Node* searchNode(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return searchNode(root->left, value);
    }
    else {
        return searchNode(root->right, value);
    }
}

/* Función para encontrar el camino entre dos nodos */
vector<Node*> findPath(Node* root, int n1, int n2) {
    vector<Node*> path1, path2;
    findNodePath(root, n1, path1);
    findNodePath(root, n2, path2);

    vector<Node*> path;
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
        path.push_back(path1[i]);
        i++;
    }
    return path;
}

/* Función auxiliar para encontrar el camino hacia un nodo */
bool findNodePath(Node* root, int n, vector<Node*>& path) {
    if (root == nullptr) {
        return false;
    }
    path.push_back(root);
    if (root->data == n) {
        return true;
    }
    if (findNodePath(root->left, n, path) || findNodePath(root->right, n, path)) {
        return true;
    }
    path.pop_back();
    return false;
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

    /* Encontrar el camino entre dos nodos */
    vector<Node*> path = findPath(root, 20, 80);

    /* Imprimir el camino */
    cout << "Camino más corto entre 20 y 80: ";
    for (Node* node : path) {
        cout << node->data << " ";
    }
    cout << endl;

    return 0;
}