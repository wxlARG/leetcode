#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node)
{
    ListNode* p = node->next;
    node->val=p->val;
    node->next=p->next;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;

    ListNode* q = new ListNode(2);
    p->next = q;
    p=q;

    q = new ListNode(3);
    ListNode* tmp = q;
    p->next = q;
    p = q;

    q = new ListNode(4);
    p->next = q;
    p = q;

    deleteNode(tmp);
    p=head;
    while(p)
    {
        cout << p->val << endl;
        p=p->next;
    }

    return 0;
}
