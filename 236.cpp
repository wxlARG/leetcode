#include"common.h"
using namespace std;

TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, bool& pf, bool& qf) {
    if(root==NULL) return NULL;
    if(root->val==p->val) pf=true;
    if(root->val==q->val) qf=true;
    bool lpf=false, lqf=false, rpf=false, rqf=false;
    TreeNode* node=helper(root->left, p, q, lpf, lqf);
    if(node) return node;
    node=helper(root->right, p, q, rpf, rqf);
    if(node) return node;
    pf|=(lpf|rpf), qf|=(lqf|rqf);
    if(pf && qf) return root;
    return NULL;
}

TreeNode* lowestCommonAncestor_solution1(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool pf=false, qf=false;
    return helper(root, p, q, pf, qf);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q) return root;
    auto left=lowestCommonAncestor(root->left, p, q);
    auto right=lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left==NULL? right: left;
}

int main() {
    auto root=create_tree({"3","5","1","6","2","0","8","null","null","7","4"});
    auto node=lowestCommonAncestor(root, root->left, root->right);
    cout << node->val << endl;
}
