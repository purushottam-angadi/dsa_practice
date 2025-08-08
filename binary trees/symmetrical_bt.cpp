#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool symmetrical(Node *left, Node* right)
{
    if(left==NULL || right==NULL)
    {
        return left==right;
    }
    if(left->data!=right->data)
    {
        return false;
    }
  
    bool leftt=symmetrical(left->left, right->right);
    bool rightt=symmetrical(left->right, right->left);
    if(!leftt || !rightt)
    {
        return false;
    }
    return true;
  
  
}
bool issymmetrical(Node* root)
{
return root==NULL || symmetrical(root->left,root->right);
}



int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->right = new Node(3);  // Not mirroring the left subtree
    // No right->left node, so structure is asymmetric

    cout << issymmetrical(root) << endl;  // This will output 0
}