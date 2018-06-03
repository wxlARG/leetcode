#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool helper(TreeNode* left, TreeNode* right) {
    if(left==NULL || right==NULL) return left==right;
    return (left->val==right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric_solution1(TreeNode* root) {
    if(root==NULL) return true;
    return helper(root->left, root->right);
}

bool isSymmetric(TreeNode* root) {
    vector<TreeNode*> cache1={root}, cache2;
    vector<TreeNode*> *p1=&cache2, *p2=&cache1;
    while(p2->size()) {
        swap(p1, p2);
        for(int s=0, e=int(p1->size()-1); s<=e; ++s, --e) {
            if(p1->at(s)==NULL || p1->at(e)==NULL) {
                if(p1->at(s)!=p1->at(e)) return false;
                else continue;
            } else {
                if(p1->at(s)->val!=p1->at(e)->val) return false;
            }
        }
        p2->clear();
        for(auto &v: *p1) {
            if(v==NULL) continue;
            p2->push_back(v->left);
            p2->push_back(v->right);
        }
    }
    return true;
}

int main() {
    cout << isSymmetric(create_tree({"1", "2", "2", "3", "4", "4", "3"})) << endl;
    cout << isSymmetric(create_tree({"1", "2", "2", "null", "3", "null", "3"})) << endl;
    cout << isSymmetric(create_tree({"1", "2", "3"})) << endl;
}
