
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* rightest(Node* root)
{
    while(root->right) root=root->right;
    return root;
}
Node* helper(Node* root)
{
   if(root->left==NULL)
   {
    return root->right;
   }
   else if(root->right==NULL)
   {
    return root->left;
   }
   else{
    Node* rightchild= root->right;
    Node* rightestnode= rightest(root->left);
    rightestnode->right= rightchild;
    return root->left;
   }
}
Node *deleteNode(Node *root, int value)
{
   if(root==NULL) return NULL;
   if(root->data==value)
   {
    return helper(root);
   }
    else{
        Node* temp=root;
        while(root!=NULL)
        {  
            if(root->data>value)
            {
                  root=root->left;
            if(root!=NULL && root->data==value)
            {
               root= helper(root);
               break;
            }
            else{
                root= root->left;
            }
            }

            
             else
            {
                  root=root->right;
            if(root!=NULL && root->data==value)
            {
               root= helper(root);
               break;
            }
             else{
                root= root->right;
            }
            }
          
        }
        return temp;
    }

}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Try deleting a node with two children
    root = deleteNode(root, 50); // deleting root node

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}