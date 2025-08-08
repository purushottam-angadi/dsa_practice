#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value){
      data=value;
      left=nullptr;
      right=nullptr;
    }
};

Node* lca(Node *root, int p, int q)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root)
    {
        if(root->data>p && root->data<q)
        {
            return root;
        }
        else if(p>root->data && root->data<q)
        {
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
}

    int main() {
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(40);

    int p = 5, q = 30;
    Node* ancestor = lca(root, p, q);
    
    if (ancestor) {
        cout << "LCA of " << p << " and " << q << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}


   