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


Node* lowestancestor(Node* root,Node* p,Node* q)
{
  if(root==NULL || root==p || root==q)
  {
    return root;
  }
  Node* left=lowestancestor(root->left,p,q);
  Node* right=lowestancestor(root->right,p,q);
  if(left==NULL)
  {
    return right;
  }
  else if (right==NULL){
    return left;
  }
  else{
    return root;
  }
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

        Node* p = root->right->left;   // Node with value 4
    Node* q = root->right->right;  // Node with value 5

    Node* lca = lowestancestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;


}
