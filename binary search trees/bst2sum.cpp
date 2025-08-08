
#include <iostream>
#include <climits>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTiterator
{

    stack<Node *> st;
    bool reverse= true;

public:
    BSTiterator(Node *root, bool isReverse)
    {
        reverse= isReverse;
        pushall(root);
       
    }

    int next()
    {
        Node* temp=st.top();
        st.pop();
        if(!reverse) pushall(temp->right);
        else pushall(temp->left);
        return temp->data;

    }
    bool hasnext()
    {
        return !st.empty();
    }

private:
    void pushall(Node *root)
    {

        while (root)
        {
            st.push(root);
            if(reverse==true) 
            {
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
};

class Solution
{
   public:
   bool findtarget(Node* root, int target)

   {
        BSTiterator* l =new BSTiterator(root,0);
        BSTiterator* r =new BSTiterator(root,1);
   

   int i= l->next();
   int j= r->next();
    while(i<j)
    {
        if(i+j==target)
        {
           return true;
        }
        else if(i+j<target){
            i=l->next();
        }
        else{
            j=r->next();
        }
    }
    return false;
}

};
main()
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->right->right = new Node(40);
    Solution s;
    cout<<s.findtarget(root, 70)<<endl;
}
