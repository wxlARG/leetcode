#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include"common.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p1=dummy, *p2=dummy;
    for(int i=0; i<n+1; ++i)
        p1 = p1->next;
    while(p1) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = p2->next->next;
    return dummy->next;
}

int main() {
    ListNode *head = removeNthFromEnd(create_list({1, 2, 3, 4, 5}), 1);
    for(ListNode *p = head; p; p=p->next)
        cout << p->val << "\t";
    cout << endl;
}
