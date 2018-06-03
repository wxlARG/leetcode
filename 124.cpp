#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper(TreeNode* root, int &max_path, int &max_val) {
    if(root==NULL) {
        max_path=0;
        max_val=INT_MIN;
        return;
    }
    int left_path=0, left_val=0, right_path=0, right_val=0;
    helper(root->left, left_path, left_val);
    helper(root->right, right_path, right_val);
    max_path = max(left_path>0? left_path: 0, right_path>0? right_path: 0)+root->val;
    max_val = max(root->val+(left_path>0? left_path: 0)+(right_path>0? right_path: 0), max(left_val, right_val));
}

int maxPathSum(TreeNode* root) {
    int max_path=0, max_val=0;
    helper(root, max_path, max_val);
    return max_val;
}

int main() {
    cout << maxPathSum(create_tree({"1", "2", "3"})) << endl;
    cout << maxPathSum(create_tree({"-3"})) << endl;
    cout << maxPathSum(create_tree({"2", "-1"})) << endl;
}
