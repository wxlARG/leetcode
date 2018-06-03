#include"common.h"
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    ListNode* fake_head=new ListNode(0);
    fake_head->next=head;
    for(auto p=fake_head; p; ) {
        if(p->next!=NULL && p->next->val==val) p->next=p->next->next;
        else p=p->next;
    }
    return fake_head->next;
}

int main() {
    auto head=removeElements(create_list({1, 2, 6, 3, 4, 5, 6}), 6);
    for(ListNode* p=head; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
