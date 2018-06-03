#include"common.h"
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    for(auto node=head; node; ) {
        auto next=node->next;
        node->next=new RandomListNode(node->label);
        node=node->next;
        node->next=next;
        node=next;
    }
    for(auto node=head; node; ) {
        auto copy_node=node->next;
        if(node->random) copy_node->random=node->random->next;
        node=copy_node->next;
    }
    RandomListNode* new_head=NULL;
    for(auto p=head; p; ) {
        auto q=p->next;
        if(new_head==NULL) new_head=q;
        p->next=q->next;
        p=p->next;
        if(p) q->next=p->next;
        else q->next=NULL;
    }
    return new_head;
}

int main() {
    RandomListNode* n1=new RandomListNode(1);
    RandomListNode* n2=new RandomListNode(2);
    n1->next=n2;
    auto n_copy = copyRandomList(n1);
    cout << n_copy->label << endl;
    cout << n_copy->next->label << endl;
}
