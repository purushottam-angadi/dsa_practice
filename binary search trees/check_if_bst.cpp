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

bool checkbst(Node *root, int minvalue, int maxvalue)
{
   if(root==NULL)
   {
    return true;
   }
    if(root->data>=maxvalue || root->data<=minvalue)
    {
        return false;
    }
   bool left= checkbst(root->left,minvalue,root->data);
   bool right= checkbst(root->right,root->data,maxvalue);

   if(!left || !right)

   {
      return false;
   }
   return true;
//  return checkbst(root->left, minvalue, root->data) &&
//            checkbst(root->right, root->data, maxvalue);
}
bool isBST(Node* root) {
    return checkbst(root, INT_MIN, INT_MAX);
}

int main()
{
Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);

cout << (isBST(root) ? "BST is valid" : "BST is invalid") << endl;

}
   