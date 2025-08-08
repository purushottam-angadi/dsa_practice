#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Find minimum value in BST
int findMin(Node* root) {
    if (!root) throw runtime_error("Tree is empty");
    Node* curr = root;
    while (curr->left) {
        curr = curr->left;
    }
    return curr->data;
}

// Find maximum value in BST
int findMax(Node* root) {
    if (!root) throw runtime_error("Tree is empty");
    Node* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    return curr->data;
}

int main() {
    // Sample BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);

    cout << "Minimum: " << findMin(root) << endl;
    cout << "Maximum: " << findMax(root) << endl;

    return 0;
}