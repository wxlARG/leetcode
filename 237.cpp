#include"common.h"
using namespace std;

void deleteNode(ListNode* node) {
    auto next=node->next;
    node->next=next->next;
    node->val=next->val;
}

int main() {
    auto head=create_list({4,5,1,9});
    deleteNode(head->next);
    for(auto p=head; p; p=p->next) cout << p->val << "\t";
    cout << endl;
}
