#include"common.h"
using namespace std;

ListNode *detectCycle(ListNode *head) {
    if(head==NULL) return NULL;
    for(ListNode *p=head, *q=head->next; q!=NULL && q->next!=NULL; p=p->next, q=q->next->next) {
        if(p==q) {
            q=q->next;
            for(ListNode* r=head; r!=q; r=r->next, q=q->next);
            return q;
        }
    }
    return NULL;
}

int main() {
    ListNode *head = create_list({1, 2});
    head->next->next=head;
    auto node=detectCycle(head);
    cout << node->val << endl;
}
