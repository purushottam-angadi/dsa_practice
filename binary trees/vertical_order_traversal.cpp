  #include <iostream>
#include <vector>
#include <queue>
#include <set>

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


vector<vector<int>> vertical(Node* root)
{
    queue<pair<Node*,pair<int,int>>> todo;
    map<int, map<int,multiset<int>>> nodes;
    todo.push({root,{0,0}});
    while(!todo.empty())
    {
       auto it= todo.front();
       todo.pop();
       Node* node=it.first;
       int x= it.second.first;
       int y= it.second.second;

       nodes[x][y].insert(node->data);
       if(node->left) todo.push({node->left,{x-1,y+1}});
       if(node->right) todo.push({node->right,{x+1,y+1}});
    
    }
  vector<vector<int>> ans;
  for(auto it: nodes)
  {
    vector<int> col;
    for(auto itt: it.second )
    {
        col.insert(col.end(),itt.second.begin(),itt.second.end());
    }
    ans.push_back(col);
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
    vector<vector<int>>  answer= vertical(root);
        for (const auto& row : answer) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }


}
