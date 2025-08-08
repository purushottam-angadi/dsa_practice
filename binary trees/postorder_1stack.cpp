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

vector<int> postorder(Node *root)
{
    Node *cur = root;
    stack<Node *> st;
    vector<int> post;
    while (!st.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                post.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);
                }
            }
            else cur = temp;
        }
    }
    return post;
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

    vector <int> answer=postorder(root);
    for(auto val: answer)
    {
        cout<<val<<" ";
    }
}
