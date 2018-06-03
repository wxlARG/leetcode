#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void flatten(TreeNode* root) {
    TreeNode* cur=root;
    while(cur!=NULL) {
        if(cur->left==NULL) {
            cur = cur->right;
        } else {
            auto tmp=cur->left;
            while(tmp->right!=NULL) tmp=tmp->right;
            tmp->right=cur->right;
            cur->right=cur->left;
            cur->left=NULL;
            cur=cur->right;
        }
    }
}

int main() {
    auto root = create_tree({"1", "2", "5", "3", "4", "null", "6"});
    flatten(root);
    cout << print_tree(root) << endl;
}
