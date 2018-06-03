#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL || q==NULL) {
        if(p==NULL && q==NULL) return true;
        return false;
    }
    if(p->val!=q->val) return false;
    if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return true;
    return false;
}

int main() {
    cout << isSameTree(create_tree({"1", "2", "3"}), create_tree({"1", "2", "3"})) << endl;
    cout << isSameTree(create_tree({"1", "2"}), create_tree({"1", "null", "2"})) << endl;
    cout << isSameTree(create_tree({"1", "2", "1"}), create_tree({"1", "1", "2"})) << endl;
}
