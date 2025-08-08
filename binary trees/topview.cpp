  #include <iostream>
#include <vector>
#include <queue>
#include <map>
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


vector<int> topview(Node* root)
{
    queue<pair<Node*, int>> q;
    vector<int> ans;
    map<int,int> mpp;
    q.push({root,0});
    while(!q.empty())
{
    auto it=q.front();
    q.pop();
    Node* node= it.first;
    int line= it.second;

    if(mpp.find(line)==mpp.end()) mpp[line]=node->data;

    if(node->left) q.push({node->left,line-1});
    if(node->right) q.push({node->right,line+1});

}
for(auto it : mpp)
{
    ans.push_back(it.second);
}
return ans;

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
    vector<int> answer= topview(root);
    for(auto val :answer)
    {
        cout<<val<<" ";
    }
  
}
