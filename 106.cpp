#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

TreeNode* helper(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
    if(ps>pe) return NULL;
    TreeNode* n=new TreeNode(postorder[pe]);
    int left_len=0;
    for(int i=is; i<=ie; ++i) {
        if(inorder[i]==postorder[pe]) break;
        ++left_len;
    }
    n->left = helper(inorder, is, is+left_len-1, postorder, ps, ps+left_len-1);
    n->right = helper(inorder, is+left_len+1, ie, postorder, ps+left_len, pe-1);
    return n;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

int main() {
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
    auto t = buildTree(inorder, postorder);
    cout << print_tree(t) << endl;
}
