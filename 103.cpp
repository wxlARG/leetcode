#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==NULL) return res;
    vector<TreeNode*> s1, s2;
    vector<TreeNode*> *ps1=&s1,*ps2=&s2;
    s2.push_back(root);
    while(!ps2->empty()) {
        swap(ps1, ps2);
        res.push_back(vector<int>());
        while(!ps1->empty()) {
            TreeNode* t=ps1->back();
            ps1->pop_back();
            res.back().push_back(t->val);
            if(res.size() & 1) {
                if(t->left) ps2->push_back(t->left);
                if(t->right) ps2->push_back(t->right);
            } else {
                if(t->right) ps2->push_back(t->right);
                if(t->left) ps2->push_back(t->left);
            }
        }
    }
    return res;
}

int main() {
    auto res = zigzagLevelOrder(create_tree({"3", "9", "20", "null", "null", "15", "7"}));
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
