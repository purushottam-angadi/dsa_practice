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

bool rtn(Node *root, vector<int> &arr)
{
    if(root==NULL)
    {
        return false;
    }
    arr.push_back(root->data);
   if(root->data==5)
   {
    return true;
   }

    bool left=rtn(root->left, arr);
    bool right=rtn(root->right, arr);
    if(!left && !right)
    {
        arr.pop_back();
        return false;
    }
    return true;
  
  
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
    vector<int> arr;
    rtn(root, arr);
    for(auto val: arr)
    {
        cout<<val<<" ";
    }
   
}