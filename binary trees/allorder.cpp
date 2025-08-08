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


void allorder(Node* root)
{
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    stack<pair<Node*,int>> st;
    st.push({root,1});
    if(root==NULL ) return;
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }

         else if(it.second==2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }

         else {
            postorder.push_back(it.first->data);
        
        }


    }
    for(auto val: preorder)
    {
        cout<<val<<" ";
       
    }
     cout<<endl;
     for(auto val: inorder)
    {
        cout<<val<<" ";
     
    }
       cout<<endl;
     for(auto val: postorder)
    {
        cout<<val<<" ";
    }
            cout<<endl;

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
    allorder(root);
}
