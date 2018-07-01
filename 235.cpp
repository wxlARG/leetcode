#include"common.h"
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val>q->val) return lowestCommonAncestor(root, q, p);
    if(root->val==p->val || root->val==q->val) return root;
    if(p->val<root->val && root->val<q->val) return root;
    if(root->val>q->val) return lowestCommonAncestor(root->left, p, q);
    return lowestCommonAncestor(root->right, p, q);
}

int main() {
    auto root=create_tree({"6","2","8","0","4","7","9","null","null","3","5"});
    auto node=lowestCommonAncestor(root, root->left, root->right);
    cout << node->val << endl;
}
