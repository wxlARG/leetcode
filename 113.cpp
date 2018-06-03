#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper(TreeNode* root, int sum, vector<int>& cache, vector<vector<int>>& res) {
    if(root==NULL) return;
    else if(root->left==NULL && root->right==NULL) {
        if(root->val==sum) {
            cache.push_back(sum);
            res.push_back(cache);
            cache.pop_back();
        }
        return;
    }
    cache.push_back(root->val);
    helper(root->left, sum-root->val, cache, res);
    helper(root->right, sum-root->val, cache, res);
    cache.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> cache;
    helper(root, sum, cache, res);
    return res;
}

int main() {
    auto res = pathSum(create_tree({"5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "5", "1"}), 22);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
