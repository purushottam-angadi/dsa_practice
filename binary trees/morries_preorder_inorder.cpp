// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }
// };


// vector<int> inorder(Node* root)
// {
//     vector<int> ans;
//     Node* cur= root;
//     while(cur!=NULL)
//     {
//         if(cur->left==NULL)
//         {
//             ans.push_back(cur->data);
//             cur=cur->right;
//         }
//         else
//         {
//             Node* prev=cur->left;
//             while(prev->right!=cur && prev->right!=NULL )
//             {
//                 prev=prev->right;
//             }

//             if(prev->right==NULL)
//             {
//                 prev->right=cur;
//                 cur=cur->left;
//             }
//             else
//             {
//                prev->right=NULL;
//                ans.push_back(cur->data);
//                cur=cur->right;
//             }
//         }
//     }
//     return ans;
   
// }

// int main()
// {
//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right = new Node(3);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);
    
//      vector<int> answer=inorder(root);
//      for(auto val:answer)
//      {
//         cout<<val<<" ";
//      }
    
// }


//preorder

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


vector<int> preorder(Node* root)
{
    vector<int> ans;
    Node* cur= root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            ans.push_back(cur->data);
            cur=cur->right;
        }
        else
        {
            Node* prev=cur->left;
            while(prev->right!=cur && prev->right!=NULL )
            {
                prev=prev->right;
            }

            if(prev->right==NULL)
            {
                prev->right=cur;
                ans.push_back(cur->data);
                cur=cur->left;
            }
            else
            {
               prev->right=NULL;
               
               cur=cur->right;
            }
        }
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
    
     vector<int> answer=preorder(root);
     for(auto val:answer)
     {
        cout<<val<<" ";
     }
    
}
