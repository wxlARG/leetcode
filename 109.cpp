#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

TreeNode* helper(ListNode* head) {
    if(head==NULL) return NULL;
    if(head->next==NULL) return new TreeNode(head->val);
    auto p=head, q=head;
    ListNode* r=NULL;
    while(q!=NULL && q->next!=NULL) {
        r=p;
        p=p->next;
        q=q->next->next;
    }
    auto root = new TreeNode(p->val);
    if(r!=NULL) r->next=NULL;
    root->left = helper(head);
    root->right = helper(p->next);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    return helper(head);
}

int main() {
    auto head = create_list({-10,-3,0,5,9});
    auto res = sortedListToBST(head);
    cout << print_tree(res) << endl;
}
