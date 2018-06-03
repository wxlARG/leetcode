#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

ListNode* partition(ListNode* head, int x) {
    ListNode *le=new ListNode(0), *p=le, *gt=new ListNode(0), *q=gt;
    for(ListNode *r=head; r; r=r->next) {
        if(r->val<x) {
            p->next = r;
            p=p->next;
        } else {
            q->next = r;
            q=q->next;
        }
    }
    p->next=gt->next;
    q->next=NULL;
    return le->next;
}

int main() {
    auto res = partition(create_list({1, 4, 3, 2, 5, 2}), 3);
    for(ListNode* p=res; p; p=p->next) {
        cout << p->val << "\t";
    }
    cout << endl;
}
