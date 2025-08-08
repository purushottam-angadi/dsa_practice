#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);
    Node *temp = root;
    while (true)
    {
        if (temp->data > value)
        {
            if (temp->left)
                temp = temp->left;
            else
            {
                temp->left = new Node(value);
                break;
            }
        }

        else
        {
            if (temp->right)
                temp = temp->right;
            else
            {
                temp->right = new Node(value);
                break;
            }

        }
    }
    return root;
}
void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    // Sample BST
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);
    Node *answer = insertNode(root, 15);
    inOrder(answer);
}