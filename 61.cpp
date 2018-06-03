#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    int len = 0;
    for(ListNode *r=head; r; r=r->next) ++len;
    if(len<=1) return head;
    k = k%len;
    if(k==0) return head;
    ListNode *p=head, *q=head;
    for(int i=0; i<k; ++i) {
        q = q->next;
    }
    while(q->next) {
        p = p->next;
        q = q->next;
    }
    ListNode *new_head = p->next;
    p->next = NULL;
    q->next = head;
    return new_head;
}

int main() {
    auto head = rotateRight(create_list({1, 2}), 2);
    for(ListNode* p=head; p; p=p->next) {
        cout << p->val << "\t";
    }
    cout << endl;
}
