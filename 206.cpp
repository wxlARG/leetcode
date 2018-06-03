#include"common.h"
using namespace std;

ListNode* reverseList_solution1(ListNode* head) {
    if(head==NULL) return NULL;
    ListNode *p=head, *q=p->next;
    while(q) {
        ListNode* r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head->next=NULL;
    return p;
}

ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    auto new_head=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

int main() {
    auto head = reverseList(create_list({1, 2, 3, 4, 5}));
    for(auto p=head; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
