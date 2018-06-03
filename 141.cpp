#include"common.h"
using namespace std;

bool hasCycle(ListNode *head) {
    if(head==NULL) return false;
    for(ListNode *p=head, *q=head->next; q!=NULL && q->next!=NULL; p=p->next, q=q->next->next) {
        if(p==q) return true;
    }
    return false;
}

int main() {
    ListNode *head = create_list({1, 2, 3});
    cout << hasCycle(head) << endl;
}
