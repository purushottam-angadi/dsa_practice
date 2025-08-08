#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* formbst(vector<int>pre, int upperbound, int& i)
{   
     if(i>pre.size()-1 || pre[i]> upperbound )
     {
        return NULL;
     }

     Node* root = new Node(pre[i++]);
     root->left=formbst(pre,root->data,i);
     root->right=formbst(pre,upperbound,i);
     return root;
}
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    int i = 0;
    Node* root = formbst(pre, INT_MAX, i);

    cout << "Inorder traversal of BST: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
   




// brute:-
// #include <iostream>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// TreeNode* insert(TreeNode* root, int val) {
//     if (!root) return new TreeNode(val);

//     if (val < root->val)
//         root->left = insert(root->left, val);
//     else
//         root->right = insert(root->right, val);

//     return root;
// }

// TreeNode* buildBSTFromPreorder(vector<int>& preorder) {
//     TreeNode* root = NULL;
//     for (int val : preorder) {
//         root = insert(root, val);
//     }
//     return root;
// }

// // Helper to print inorder traversal
// void inorder(TreeNode* root) {
//     if (!root) return;
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

// int main() {
//     vector<int> preorder = {8, 5, 1, 7, 10, 12};
//     TreeNode* root = buildBSTFromPreorder(preorder);

//     cout << "Inorder traversal of BST: ";
//     inorder(root);
//     cout << endl;

//     return 0;
// }