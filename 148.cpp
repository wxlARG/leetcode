#include"common.h"
using namespace std;

ListNode* sortPart(ListNode* head, int step, int len) {
    ListNode *fake_head = new ListNode(0);
    fake_head->next=head;
    ListNode *prev=fake_head, *s=head;
    while(s!=NULL) {
        ListNode *p1=s, *q=p1, *p2=NULL;
        for(int i=1; i<step && q; ++i) q=q->next;
        if(q==NULL) {
            prev->next=p1;
            break;
        }
        p2=q->next;  
        q->next=NULL;
        q=p2;
        for(int i=1; i<step && q; ++i) q=q->next;
        if(q) {
            s=q->next;
            q->next=NULL;
        } else {
            s=NULL;
        }
        ListNode *fake_start=new ListNode(0);
        q=fake_start;
        while(p1 && p2) {
            if(p1->val<=p2->val) {
                q->next=p1;
                p1=p1->next;
            } else {
                q->next=p2;
                p2=p2->next;
            }
            q=q->next;
        }
        if(p1!=NULL) q->next=p1;
        else q->next=p2;
        while(q->next) q=q->next;
        prev->next=fake_start->next;
        delete fake_start;
        prev=q;
    }
    head = fake_head->next;
    delete fake_head;
    return head;
}

ListNode* sortList(ListNode* head) {
    int len=0;
    for(ListNode *p=head; p; p=p->next) ++len;
    for(int i=1; i<len; i*=2) head = sortPart(head, i, len);
    return head;
}

int main() {
    auto head = create_list({5, 4, 3, 2, 1, 2});
    auto res=sortList(head);
    for(auto p=res; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
