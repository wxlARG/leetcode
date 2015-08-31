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

ListNode *sortList(ListNode *head)
{
	if(head == NULL || head->next == NULL)
		return head;

	ListNode* p=head, *q=head, *r=NULL;
	while(q!=NULL && q->next!=NULL)
	{
		r=p;
		p=p->next;
		q=q->next->next;
	}

	r->next = NULL;
	ListNode* res1=sortList(head);
	ListNode* res2=sortList(p);
	if(res1 != NULL && res2 != NULL)
	{
		ListNode* newhead = NULL;
		ListNode* r=NULL;
		p=res1;
		q=res2;

		while(p!=NULL && q!=NULL)
		{
			if(p->val<q->val)
			{
				if(newhead==NULL)
					newhead=p;
				else
					r->next=p;
				r=p;
				p=p->next;
			}
			else
			{
				if(newhead==NULL)
					newhead=q;
				else
					r->next=q;
				r=q;
				q=q->next;
			}
		}

		if(p!=NULL)
		{
			if(newhead==NULL)
				newhead=p;
			else
				r->next=p;
		}

		if(q!=NULL)
		{
			if(newhead==NULL)
				newhead=q;
			else
				r->next=q;
		}
		return newhead;
	}
	else if(res1 != NULL)
		return res1;
	else
		return res2;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

	ListNode* q = new ListNode(4);
	p->next = q;
	p=q;

	q = new ListNode(3);
	p->next = q;
	p = q;


	q = new ListNode(5);
	p->next = q;
	p=q;

	q = new ListNode(2);
	p->next = q;
	p = q;

	ListNode* result = sortList(head);
	p=result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}

	return 0;
}
