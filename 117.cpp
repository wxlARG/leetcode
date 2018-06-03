#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void connect(TreeLinkNode *root) {
    if(root==NULL) return;
    root->next=NULL;
    TreeLinkNode* last_link=root;
    while(last_link!=NULL) {
        TreeLinkNode *cur_link=new TreeLinkNode(0), *p=cur_link, *q=last_link;
        for(; q; q=q->next) {
            if(q->left!=NULL) {
                p->next=q->left;
                p=p->next;
            }
            if(q->right!=NULL) {
                p->next=q->right;
                p=p->next;
            }
        }
        last_link=cur_link->next;
    }
}

int main() {
    auto t = create_tree_link({"1", "2", "3", "4", "5", "null", "7"});
    connect(t);
    for(auto n=t; n!=NULL; n=n->left) {
        for(auto tmp=n; tmp; tmp=tmp->next) cout << tmp->val << "\t";
        cout << endl;
    }
}
