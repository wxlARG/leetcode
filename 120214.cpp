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

ListNode *swapPairs(ListNode *head)
{
	if(head == NULL)
		return NULL;
	if(head->next == NULL)
		return head;

	ListNode* p = head;
	ListNode* q = p->next;
	ListNode* r = q->next;

	while(r!=NULL && r->next!=NULL)
	{
		q->next = p;
		if(p == head) head = q;
		p->next = r->next;
		p=r;
		q=r->next;
		r = q->next;
	}     

	q->next = p;
	p->next = r;

	return head;
}

int main()
{
	ListNode* p = new ListNode(4);
	ListNode* head = p;

	p = new ListNode(3);
	p->next = head;
	head = p;

	p = new ListNode(2);
	p->next = head;
	head = p;

	p = new ListNode(1);
	p->next = head;
	head = p;

	p = swapPairs(head);
	while(p != NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
