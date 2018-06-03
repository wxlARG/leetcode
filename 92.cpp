#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

ListNode* reverseBetween(ListNode* head, int m, int n) {
    auto h=new ListNode(0);
    h->next=head;
    ListNode *s=h, *e=h, *p=h;
    for(int i=0; i<=n; ++i) {
        if(i<m) {
            s=p;
            p=p->next;
        } else if(i==m) {
            e=p;
            p=p->next;
        } else {
            e->next=p->next;
            p->next=s->next;
            s->next = p;
            p=e->next;
        }
    }
    return h->next;
}

int main() {
    auto head = reverseBetween(create_list({1, 2, 3, 4}), 2, 4);
    for(auto p=head; p; p=p->next) {
        cout << p->val << "\t";
    }
    cout << endl;
}
