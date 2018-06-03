#include"common.h"
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA=0, lenB=0;
    for(auto p=headA; p; p=p->next) ++lenA;
    for(auto p=headB; p; p=p->next) ++lenB;
    for(; lenA>lenB; --lenA) headA=headA->next;
    for(; lenB>lenA; --lenB) headB=headB->next;
    while(headA!=headB) {
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}

int main() {
    ListNode* headA=create_list({1, 2, 3, 4});
    ListNode* headB=create_list({1, 2, 3, 4});
    ListNode* res=getIntersectionNode(headA, headB);
    if(res) cout << res->val << endl;
    else cout << "NULL" << endl;
}
