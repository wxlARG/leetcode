#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

TreeNode* helper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
    if(ps>pe) return NULL;
    TreeNode* n=new TreeNode(preorder[ps]);
    int left_len=0;
    for(int i=is; i<=ie; ++i) {
        if(inorder[i]==preorder[ps]) break;
        ++left_len;
    }
    n->left = helper(preorder, ps+1, ps+left_len, inorder, is, is+left_len-1);
    n->right = helper(preorder, ps+left_len+1, pe, inorder, is+left_len+1, ie);
    return n;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

int main() {
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    auto t = buildTree(preorder, inorder);
    cout << print_tree(t) << endl;
}
