#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include"common.h"
using namespace std;

int helper(TreeNode* root, int val) {
    if(root->left==NULL && root->right==NULL) return val*10+root->val;
    else if(root->left==NULL) return helper(root->right, val*10+root->val);
    else if(root->right==NULL) return helper(root->left, val*10+root->val);
    else return helper(root->left, val*10+root->val)+helper(root->right, val*10+root->val);
}

int sumNumbers(TreeNode* root) {
    if(root==NULL) return 0;
    return helper(root, 0);
}

int main() {
    cout << sumNumbers(create_tree({"1", "2", "3"})) << endl;
    cout << sumNumbers(create_tree({"4", "9", "0", "null", "1"})) << endl;
}
