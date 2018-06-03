#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

vector<TreeNode*> helper(int start, int end) {
    if(start>end) return vector<TreeNode*>(1, NULL);
    vector<TreeNode*> res;
    for(int i=start; i<=end; ++i) {
        auto left = helper(start, i-1);
        auto right = helper(i+1, end);
        for(auto &l: left) {
            for(auto &r: right) {
                auto root = new TreeNode(i);
                root->left=l;
                root->right=r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if(n==0) return vector<TreeNode*>();
    return helper(1, n);
}

int main() {
    auto res = generateTrees(4);
    for(auto &v: res) {
        cout << print_tree(v) << endl;
    }
}
