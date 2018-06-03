#include<iostream>
#include<vector>
#include<unordered_map>
#include"common.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1, *p2, *r = NULL;
    ListNode *res = NULL;
    int v = 0;
    p1 = l1;
    p2 = l2;

    while(p1 != NULL || p2 != NULL || v != 0) {
        int val1 = p1 ? p1->val : 0;
        int val2 = p2 ? p2->val : 0;
        int val = val1 + val2 + v;
        v = val / 10;
        ListNode *t = new ListNode(val % 10);
        if(res == NULL)  
            r = res = t;
        else 
            r->next = t;
        r = t;
        p1 = p1 ? p1->next : p1;
        p2 = p2 ? p2->next : p2;
    }
    return res;
}

int main() {
    ListNode* l1 = create_list({2, 4, 3});
    ListNode* l2 = create_list({5, 6, 4});
    ListNode* res = addTwoNumbers(l1, l2);
    while(res != NULL) {
        cout << res->val << "\t";
        res = res->next;
    }
    cout << endl;
}
