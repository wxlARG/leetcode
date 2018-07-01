#include"common.h"
using namespace std;

bool isPalindrome(ListNode* head) {
    ListNode *p=head, *q=head;
    while(q && q->next) {
        p=p->next;
        q=q->next->next;
    }
    ListNode *cur=NULL, *next=head;
    while(next!=p) {
        auto tmp=next->next;
        next->next=cur;
        cur=next;
        next=tmp;
    }
    if(q) p=p->next;
    for(;cur!=NULL && p!=NULL; p=p->next, cur=cur->next) {
        if(cur->val!=p->val) return false;
    }
    return true;
}

int main() {
    cout << isPalindrome(create_list({1, 2})) << endl;
    cout << isPalindrome(create_list({1, 2, 2, 1})) << endl;
}
