#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include"common.h"
using namespace std;

struct great {
    bool operator() (const ListNode* x, const ListNode* y) const {return x->val>y->val;}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *head = new ListNode(0), *p = head;
    using mypq_type = priority_queue<ListNode*, std::vector<ListNode*>, great>;
    mypq_type pq;
    for(int i=0; i<lists.size(); ++i) {
        if(lists[i] != NULL) 
            pq.push(lists[i]);
    }
    while(!pq.empty()) {
        ListNode *node = pq.top();
        pq.pop();
        p->next = node;
        p = p->next;
        if(node->next)
            pq.push(node->next);
    }
    return head->next;
}

int main() {
    ListNode *h1 = create_list({1, 2, 7});
    ListNode *h2 = create_list({1, 3, 4});
    ListNode *h3 = create_list({5, 6, 7});
    vector<ListNode*> lists = {h1, h2, h3};
    ListNode *head = mergeKLists(lists);
    for(ListNode *p = head; p; p=p->next)
        cout << p->val << "\t";
    cout << endl;
}
