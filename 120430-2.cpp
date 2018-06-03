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

ListNode *partition(ListNode *head, int x)
{
	ListNode* p = head;
	ListNode* smallhead=NULL, *psmall=NULL;
	ListNode* largehead=NULL, *plarge=NULL;

	while(p!=NULL)
	{
		if(p->val < x)
		{
			if(smallhead == NULL)
				smallhead = p;
			else
				psmall->next = p;
			psmall = p;
		}
		else
		{
			if(largehead == NULL)
				largehead = p;
			else
				plarge->next = p;
			plarge = p;
		}
		p=p->next;
	}

	if(psmall != NULL)
		psmall->next = largehead;
	else
		smallhead = largehead;

	if(plarge != NULL)
		plarge->next = NULL;

	return smallhead;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

	ListNode* q = new ListNode(4);
	p->next = q;
	p=p->next;

	q = new ListNode(3);
	p->next = q;
	p=p->next;

	q = new ListNode(2);
	p->next = q;
	p=p->next;

	q = new ListNode(5);
	p->next = q;
	p=p->next;

	q = new ListNode(2);
	p->next = q;
	p=p->next;

	ListNode* result = partition(head,3);
	p = result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	return 0;
}
