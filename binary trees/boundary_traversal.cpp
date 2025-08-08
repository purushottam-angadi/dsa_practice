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
bool isLeaf(Node* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}
void leftbound(Node* root, vector <int> &res)
{
    Node* cur=root->left;
    while(cur)
    {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur=cur->left;
        else cur=cur->right;
    }

}
void rightbound(Node* root, vector <int> &res)
{
    Node* cur=root->right;
    vector<int> temp;
    while(cur)
    {
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if (cur->right) cur=cur->right;
        else cur=cur->left;
    }
    for(int i=temp.size()-1; i>=0;i++)
    {
        res.push_back(temp[i]);
    }


}
 void addleaves(Node* root, vector<int> &res)
 {
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
 if(root->left) addleaves(root->left,res);
 if(root->right) addleaves(root->right,res);

 }
vector<int> printboundary(Node* root)
{
   vector<int> res;
   if(!root) return res;
   if(!isLeaf(root)) res.push_back(root->data);
   leftbound(root,res);
   addleaves(root,res);
   rightbound(root,res);
   return res;

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
    vector<int> answer=printboundary(root);
    for(auto val: answer)
    {
        cout<<val<<" ";
    }


}
