#include"common.h"
using namespace std;

void reorderList(ListNode* head) {
    if(head==NULL || head->next==NULL) return;
    ListNode *p=head, *q=head;
    while(q->next!=NULL && q->next->next!=NULL) {
        p=p->next; 
        q=q->next->next;
    }
    q=p->next;
    p->next=NULL;
    p=head;
    for(ListNode* r=q->next; r!=NULL; ) {
        ListNode *tmp=r->next;
        r->next=q;
        if(q->next==r) q->next=NULL;
        q=r;
        r=tmp;
    }

    while(q!=NULL) {
        ListNode* n1=p->next, *n2=q->next;
        p->next=q;
        q->next=n1;
        p=n1;
        q=n2;
    }
}

int main() {
    ListNode *head = create_list({1, 2, 3, 4, 5});
    reorderList(head);
    for(auto p=head; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
