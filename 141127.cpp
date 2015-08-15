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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lenA=0,lenB=0;
	ListNode* p=headA, *q=headB;

	while(p!=NULL)
	{
		p=p->next;
		++lenA;
	}

	while(q!=NULL)
	{
		q=q->next;
		++lenB;
	}

	p=headA;
	q=headB;
	if(lenA > lenB)
		while(lenA!=lenB)
		{
			p=p->next;
			--lenA;
		}
	else
		while(lenA!=lenB)
		{
			q=q->next;
			--lenB;
		}

	while(p!=NULL)
	{
		if(p==q)
			return p;
		p=p->next;
		q=q->next;
	}
	return NULL;
}

int main()
{
	ListNode* headA = new ListNode(1);
	ListNode* p = headA;

	ListNode* q = new ListNode(2);
	p->next = q;
	p=q;

	q = new ListNode(3);
	p->next = q;
	p = q;


	q = new ListNode(4);
	p->next = q;
	p=q;

	q = new ListNode(5);
	p->next = q;
	p = q;

	ListNode* headB = new ListNode(10);
	p = headB;

	p->next = headA->next->next;

	ListNode* result = getIntersectionNode(headA,headB);
	cout << result->val << endl;

	return 0;
}
