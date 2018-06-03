#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include"common.h"
using namespace std;

ListNode* swap_list(ListNode* r, ListNode* p, ListNode* q) {
    ListNode *head = p, *t = p->next;
    while(t!=q) {
        ListNode *tmp = t->next;
        t->next = p;
        p = t;
        t = tmp;
    }
    head->next = q;
    r->next = p;
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(0);
    ListNode *r = dummy, *p = head, *q = head;
    dummy->next = head;
    while(q) {
        int i=0;
        for(; i<k && q; ++i)
            q = q->next;
        if(i<k) break;
        r = swap_list(r, p, q);
        p = q;
    }
    return dummy->next;
}

int main() {
    ListNode *h1 = create_list({1, 2, 3, 4, 5, 6});
    ListNode *head = reverseKGroup(h1, 3);
    for(ListNode *p = head; p; p=p->next)
        cout << p->val << "\t";
    cout << endl;
}
