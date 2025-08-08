#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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


int balancedbinary(Node* root)
{
   if(root==nullptr)
   {
    return 0;
   }
   int lh=balancedbinary(root->left);
   int rh=balancedbinary(root->right);
   return 1+ max(lh,rh);

}

bool answer(Node* root)
{
    return balancedbinary(root)!=-1;
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    bool depth = answer(root);
cout << "Is the binary tree height-balanced? " << (depth ? "Yes" : "No") << endl;

    return 0;


}
