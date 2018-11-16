#include"common.h"
using namespace std;

int helper(TreeNode* root, int& child_res) {
    if(root==NULL) return 0;
    int lchild_res=0, rchild_res=0;
    int left=helper(root->left, lchild_res);
    int right=helper(root->right, rchild_res);
    child_res=left+right;
    return max(root->val+lchild_res+rchild_res, left+right);
}

int rob(TreeNode* root) {
    int child_res=0;
    return helper(root, child_res);
}

int main() {
    auto root=create_tree({"3","2","3","null","3","null","1"});
    cout << rob(root) << endl;
}
