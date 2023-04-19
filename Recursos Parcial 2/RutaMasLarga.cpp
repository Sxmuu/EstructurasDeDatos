#include <iostream>
#include <vector>

using namespace std;

// Definición de un nodo del árbol binario
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Función recursiva para encontrar la rama más larga del árbol binario
vector<Node*> longestPath(Node* root) {
    if (root == nullptr) {
        return {};
    }

    // Recursivamente encontrar la rama más larga del subárbol izquierdo y derecho
    vector<Node*> leftPath = longestPath(root->left);
    vector<Node*> rightPath = longestPath(root->right);

    // Comparar las longitudes de las ramas más largas del subárbol izquierdo y derecho
    if (leftPath.size() > rightPath.size()) {
        leftPath.push_back(root);
        return leftPath;
    } else {
        rightPath.push_back(root);
        return rightPath;
    }
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

    // Encontrar la rama más larga del árbol binario
    vector<Node*> longest = longestPath(root);

    // Imprimir los nodos de la rama más larga del árbol binario
    for (int i = longest.size() - 1; i >= 0; i--) {
        cout << longest[i]->data << " ";
    }
    cout << endl;

    return 0;
}
