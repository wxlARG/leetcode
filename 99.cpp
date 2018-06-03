#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void recoverTree_solution1(TreeNode* root) {
    if(root==NULL) return;
    vector<TreeNode*> cache;
    TreeNode *node = root, *pre=NULL;
    TreeNode *node1=NULL, *node2=NULL;
    while(node!=NULL || !cache.empty()) {
        while(node!=NULL) {
            cache.push_back(node);
            node = node->left;
        }
        node = cache.back();
        cache.pop_back();
        if(pre!=NULL && pre->val>=node->val) {
            if(node1==NULL) node1=pre;  
            node2=node;
        }
        pre=node;
        node = node->right;
    }
    swap(node1->val, node2->val);
}

void recoverTree(TreeNode* root) {
    if(root==NULL) return;
    TreeNode *cur=root, *pre=NULL;
    TreeNode *node1=NULL, *node2=NULL;
    while(cur!=NULL) {
        if(cur->left==NULL) {
            if(pre!=NULL && pre->val>=cur->val) {
                if(node1==NULL) node1=pre;
                node2=cur;
            }
            pre=cur;
            cur=cur->right;
        } else {
            auto tmp=cur->left;
            while(tmp->right!=NULL && tmp->right!=cur) tmp=tmp->right;
            if(tmp->right==NULL) {
                tmp->right=cur;
                cur=cur->left;
            } else {
                if(pre!=NULL && pre->val>=cur->val) {
                    if(node1==NULL) node1=pre;  
                    node2=cur;
                }
                pre=cur;
                tmp->right=NULL;
                cur=cur->right;
            }
        }
    }
    swap(node1->val, node2->val);
}

int main() {
    //auto root = create_tree({"2", "3", "1"});
    auto root = create_tree({"0", "1"});
    recoverTree(root);
    cout << print_tree(root) << endl; 
}
