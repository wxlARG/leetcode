#include"common.h"
using namespace std;

int count(TreeNode* root) {
    if(root==NULL) return 0;
    return count(root->left)+1+count(root->right);
}

int kthSmallest(TreeNode* root, int k) {
    int leftsize=count(root->left);
    if(k==leftsize+1) return root->val;
    if(k<=leftsize) return kthSmallest(root->left, k);
    return kthSmallest(root->right, k-leftsize-1);
}

int main() {
    cout << kthSmallest(create_tree({"5","3","6","2","4","null","null","1"}), 3) << endl;
}
