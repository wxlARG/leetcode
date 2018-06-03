#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include"common.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p = new ListNode(0), *head = p;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else { 
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = (l1 ? l1: l2);
    return head->next;
}

int main() {
    ListNode *head = mergeTwoLists(create_list({1, 2, 4}), create_list({1, 3, 4}));
    for(ListNode *p = head; p; p=p->next)
        cout << p->val << "\t";
    cout << endl;
}
