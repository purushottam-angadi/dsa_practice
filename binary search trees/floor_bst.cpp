#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findFloor(Node *root)
{
    int answer = -1;
    while (root != NULL)
    {
        if (root->data <35)
        {
            answer = root->data;
            root = root->right;
        }
        else if (root->data == 35)
        {
            answer = root->data;
        }
        else{
            root= root->left;
        }
    }
    return answer;
}

int main()
{
    // Sample BST
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);
    cout << findFloor(root) << endl;
}