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

ListNode *deleteDuplicates(ListNode *head)
{
	ListNode* newhead=NULL;
	ListNode* q=NULL;
	ListNode* p = head;

	while(p!=NULL)
	{
		if(p->next!=NULL && p->val==p->next->val)
		{
			while(p->next!=NULL && p->val == p->next->val)
				p = p->next;
		}
		else
		{
			if(newhead == NULL)
				newhead = p;
			else
				q->next = p;
			q = p;
		}

		p=p->next;
	}
	if(q!=NULL)
		q->next = NULL;
	return newhead;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

	ListNode* q = new ListNode(2);
	p->next = q;
	p=p->next;

	q = new ListNode(2);
	p->next = q;
	p=p->next;

/*	q = new ListNode(2);
	p->next = q;
	p=p->next;

	q = new ListNode(3);
	p->next = q;
	p=p->next;*/

	ListNode* result = deleteDuplicates(head);
	p = result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	return 0;
}
