#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper(TreeNode* root, vector<int>& res) {
    if(root==NULL) return;
    helper(root->left, res);
    res.push_back(root->val);
    helper(root->right, res);
}

vector<int> inorderTraversal_solution1(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
}

vector<int> inorderTraversal_solution2(TreeNode* root) {
    vector<int> res;
    vector<TreeNode*> stack;
    stack.push_back(root);
    while(!stack.empty()) {
        if(stack.back()==NULL) {
            while(!stack.empty() && stack.back()==NULL) stack.pop_back();
            if(stack.empty()) break;
            auto t = stack.back();
            stack.pop_back();
            res.push_back(t->val);
            stack.push_back(t->right);
        } else {
            stack.push_back(stack.back()->left);
        }
    }
    return res;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==NULL) return res;
    vector<TreeNode*> stack;
    stack.push_back(root);
    while(!stack.empty()) {
        if(stack.back()->left==NULL) {
            TreeNode* t=NULL;
            do {
                t = stack.back();
                stack.pop_back();
                res.push_back(t->val);
            } while(!stack.empty() && t->right==NULL);
            if(t->right!=NULL) stack.push_back(t->right);
        } else {
            stack.push_back(stack.back()->left);
        }
    }
    return res;
}

int main() {
    auto res = inorderTraversal(create_tree({"1", "NULL", "2", "3"}));
    for(auto &v: res) {
        cout << v << "\t";
    }
    cout << endl;
}
