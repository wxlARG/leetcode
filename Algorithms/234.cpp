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

bool isPalindrome(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return 1;

    ListNode *p=head, *q=head, *x=NULL, *r=head->next;

    while(q->next != NULL && q->next->next != NULL)
    {
        q=q->next->next;
        p->next = x;
        x=p;
        p=r;
        r=r->next;
    }

    if(q->next != NULL)
    {
        p->next = x;
        x=p;
    }

    while(x!=NULL && r!=NULL && r->val == x->val)
    {
        x=x->next;
        r=r->next;
    }

    if(x==NULL && r==NULL)
        return 1;
    else 
        return 0;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;

    ListNode* q = new ListNode(2);
    p->next = q;
    p=q;

    q = new ListNode(3);
    p->next = q;
    p = q;

//    q = new ListNode(4);
//    p->next = q;
//    p = q;

    q = new ListNode(3);
    p->next = q;
    p = q;

    q = new ListNode(2);
    p->next = q;
    p = q;

    q = new ListNode(1);
    p->next = q;
    p = q;

    bool result = isPalindrome(head);
    cout << result << endl;

    return 0;
}
