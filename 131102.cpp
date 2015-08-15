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

void reorderList(ListNode *head)
{
	if(head == NULL)
		return;

	ListNode* p=head, *q=head;
	while(q!=NULL && q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
	}

	q=p;
	p=p->next;
	q->next=NULL;

	q=p;
	p=NULL;

	while(q!=NULL)
	{
		ListNode* r = q->next;
		q->next = p;
		p=q;
		q=r;
	}

	q=p;
	p=head;
	head=NULL;
	ListNode* r=NULL;

	while(q!=NULL)
	{
		if(head == NULL)
			head = p;
		else
			r->next=p;
		r=p;
		p=p->next;

		r->next = q;
		r=q;
		q=q->next;
	}

	if(p!=NULL)
		if(head == NULL)
			head = p;
		else
			r->next=p;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

//	ListNode* q = new ListNode(2);
//	p->next = q;
//	p=q;

//	q = new ListNode(3);
//	p->next = q;
//	p = q;

//	q = new ListNode(4);
//	p->next = q;
//	p = q;

//	q = new ListNode(5);
//	p->next = q;
//	p = q;

	reorderList(head);
	p=head;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}

	return 0;
}
