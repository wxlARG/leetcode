#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

ListNode* deleteDuplicates_solution1(ListNode* head) {
    ListNode *new_head=new ListNode(INT_MAX), *p=new_head;
    new_head->next=head;
    for(ListNode* q=head; q; q=q->next) {
        if(q->next==NULL || q->val!=q->next->val) {
            p->next=q;
            p=p->next;
        } else {
            while(q->next && q->val==q->next->val) q=q->next;
            p->next=q->next;
        }
    }
    return new_head->next;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *new_head=new ListNode(INT_MAX);
    new_head->next=head;
    for(ListNode* p=new_head; p->next; ) {
        if(p->next->next==NULL || p->next->val!=p->next->next->val) {
            p=p->next;
        } else {
            int val=p->next->val;
            while(p->next && p->next->val==val) p->next=p->next->next;
        }
    }
    return new_head->next;
}

int main() {
    ListNode* head = deleteDuplicates(create_list({1, 1, 2, 3, 3, 4, 4, 5, 5}));
    for(ListNode* p=head; p; p=p->next) {
        cout << p->val << "\t";
    }
    cout << endl;
}
