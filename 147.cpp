#include"common.h"
using namespace std;

ListNode* insertionSortList(ListNode* head) {
    ListNode *fake_head=new ListNode(INT_MIN), *prev=NULL;
    fake_head->next=head;
    for(ListNode *p=head; p; ) {
        ListNode *n=p->next, *q=fake_head;
        for(; q!=p; q=q->next) {
            if(q->val<=p->val && q->next->val>p->val) {
                ListNode* tmp=q->next;
                q->next=p;
                p->next=tmp;
                prev->next=n;
                break;
            }
        }
        if(q==p) prev=p;
        p=n;
    }
    return fake_head->next;
}

int main() {
    auto head = create_list({5, 4, 3, 2});
    auto res=insertionSortList(head);
    for(auto p=res; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
