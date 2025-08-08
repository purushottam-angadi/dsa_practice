#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int find(Node* root, int  target)
{
Node* success=NULL;
     while(root!=NULL)
     {
         if(root->data<target)
         {
           root= root->right;
         }
         else {
            success=root;
            root=root->left;

         }
     }
}


int main()
{
Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);

}
   