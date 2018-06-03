#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL) return head;
    ListNode *p=head, *q=head->next;
    while(q) {
        if(p->val!=q->val) {
            p->next = q;
            p = p->next;
        }
        q = q->next;
    }
    p->next=NULL;
    return head;
}

int main() {
    ListNode* head = deleteDuplicates(create_list({1, 1, 2, 3, 3}));
    for(ListNode* p=head; p; p=p->next) {
        cout << p->val << "\t";
    }
    cout << endl;
}
