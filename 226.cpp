#include"common.h"
using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if(root==NULL) return root;
    invertTree(root->left);
    invertTree(root->right);
    auto node=root->left;
    root->left=root->right;
    root->right=node;
    return root;
}

int main() {
    cout << print_tree(invertTree(create_tree({"4", "2", "7", "1", "3", "6", "9"}))) << endl;
}
