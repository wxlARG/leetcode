#include"common.h"
using namespace std;

ListNode* oddEvenList(ListNode* head) {
    ListNode *p1=new ListNode(0), *p2=new ListNode(0);
    ListNode *h1=p1, *h2=p2, *p=head;
    for(int i=1; p; ++i, p=p->next) {
        if((i&1)!=0) {
            p1->next=p;
            p1=p1->next;
        } else {
            p2->next=p;
            p2=p2->next;
        }
    }
    p1->next=h2->next;
    p2->next=NULL;
    return h1->next;
}

int main() {
    auto head=create_list({1, 2, 3, 4, 5});
    head=oddEvenList(head);
    for(auto p=head; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
