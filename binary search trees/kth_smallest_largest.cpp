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

void inorder(Node *root, int cnt)
{
    
    if (root == nullptr)
    {
        return ;
    }
    inorder(root->left,cnt);
    cnt++;
    inorder(root->right,cnt);
    if(cnt==2)
    {
        cout<<root->data<<endl;;
    }
  
}


int main()
{
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);

    inorder(root, 1);
   
}