#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void connect(TreeLinkNode *root) {
    if(root==NULL) return;
    root->next=NULL;
    for(auto pt=root; pt->left!=NULL; pt=pt->left) {
        auto cur = pt->left;
        for(auto n=pt; n; n=n->next) {
            cur->next=n->right;
            cur=cur->next;
            if(n->next) cur->next=n->next->left;
            else cur->next=NULL;
            cur=cur->next;
        }
    }
}

int main() {
    auto t = create_tree_link({"1", "2", "3", "4", "5", "6", "7"});
    connect(t);
    for(auto n=t; n!=NULL; n=n->left) {
        for(auto tmp=n; tmp; tmp=tmp->next) cout << tmp->val << "\t";
        cout << endl;
    }
}
