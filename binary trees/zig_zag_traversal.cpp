#include <iostream>
#include <vector>
#include <queue>
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


vector<vector<int>> levelorder(Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool flag=true;
    while(!q.empty())
    {
        int n=q.size();
        vector<int> level(n,-1);
       
        for(int i=0; i<n;i++)
        {
            Node* temp= q.front();
            q.pop();
            int index= flag?  i : (n-i-1);
            level[index]=(temp->data);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            
    
        }
         flag=!flag;
        ans.push_back(level);
       
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

    vector<vector<int>> answer= levelorder(root);
    for (auto& level : answer) {
    for (int val : level) {
        cout << val << " ";
    }
    cout << endl; 
}
}