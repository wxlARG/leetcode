#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL) {
        if(root->val==sum) return true;
        return false;
    }
    if(hasPathSum(root->left, sum-root->val)) return true;
    if(hasPathSum(root->right, sum-root->val)) return true;
    return false;
}

int main() {
    cout << hasPathSum(create_tree({"5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "null", "1"}), 22) << endl;
}
