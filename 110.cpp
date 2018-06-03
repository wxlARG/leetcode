#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool helper(TreeNode* root, int& height) {
    if(root==NULL) {
        height=0;
        return true;
    }
    int left_heigth=0, right_height=0;
    bool b_left=helper(root->left, left_heigth);
    bool b_right=helper(root->right, right_height);
    if(b_left==false || b_right==false) return false;
    else if(abs(left_heigth-right_height)>1) return false;
    height = max(left_heigth, right_height)+1;
    return true;
}

bool isBalanced(TreeNode* root) {
    int height=0;
    return helper(root, height);
}

int main() {
    cout << isBalanced(create_tree({"3", "9", "20", "null", "null", "15", "7"})) << endl;
    cout << isBalanced(create_tree({"1", "2", "2", "3", "3", "null", "null", "4", "4"})) << endl;
}
