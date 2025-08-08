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

int computeDepth(Node* node, bool goLeft) {
    int depth = 0;
    while (node) {
        depth++;
        node = goLeft ? node->left : node->right;
    }
    return depth;
}


int countnodes(Node* root)
{
   if(root==NULL)
   {
    return 0;
   }
   int lh= computeDepth(root->left, true);
   int rh= computeDepth(root->right, false);
   if(lh==rh) return (1<<lh )-1;
   else{
     return 1 + countnodes(root->left) + countnodes(root->right);

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
  
int answer=countnodes(root);
cout<< answer<<endl;

}
