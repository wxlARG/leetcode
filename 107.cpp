#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size=q.size();
        vector<int> level;
        for(int i=0; i<size; ++i) {
            TreeNode* t=q.front();
            q.pop();
            level.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        res.push_back(level);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    auto res = levelOrder(create_tree({"3", "9", "20", "null", "null", "15", "7"}));
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
