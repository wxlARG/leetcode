#include"common.h"
using namespace std;

int helper(TreeNode* root, bool is_left) {
    if(root->left==NULL && root->right==NULL) {
        if(is_left) return root->val;
        return 0;
    } else if(root->left==NULL) {
        return helper(root->right, false);
    } else if(root->right==NULL) {
        return helper(root->left, true);
    } else {
        return helper(root->right, false)+helper(root->left, true);
    }
}

int sumOfLeftLeaves(TreeNode* root) {
    if(root==NULL) return 0;
    return helper(root, false);
}

int main() {
    cout << sumOfLeftLeaves(create_tree({"3", "9", "20", "NULL", "NULL", "15", "7"})) << endl;
}
