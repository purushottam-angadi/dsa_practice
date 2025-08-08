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

void findright(Node* root, vector<int> &answer, int level)
{
   if(root==NULL)
   {
    return ;
   }
   if(level==answer.size())
   {
    answer.push_back(root->data);
   }
   findright(root->right,answer,level+1);
   findright(root->left,answer,level+1);
}

vector<int> rightview(Node* root)
{
    vector<int> answer;
    int level=0;
    findright( root,  answer, level);
    return answer;




}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->left = new Node(9);
    root->right->right = new Node(7);
    vector<int> answer= rightview(root);
    for(auto val :answer)
    {
        cout<<val<<" ";
    }
  
}
