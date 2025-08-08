#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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


int max_width(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int first,last;
        int min=q.front().second;
        int level_size = q.size();
        for(int i=0; i<level_size;i++)
        { 
             int cur=q.front().second -min;
             Node* temp=q.front().first;
             q.pop();
             if(i==0) first=cur;
             if(i==level_size-1) last=cur;
            if(temp->left!=NULL) q.push({temp->left,cur*2+1});
            if(temp->right!=NULL) q.push({temp->right,cur*2+2});
        }
        ans=max(ans,last-first+1);

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
    cout<<max_width(root)<<endl;
}
