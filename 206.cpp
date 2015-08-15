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

/*
ListNode* reverseList(ListNode* head)
{
	ListNode *p = NULL, *q=head;
	while(q != NULL)
	{
		ListNode *r = q->next;
		q->next = p;
		p=q;
		q=r;
	}
	return p;
}
*/

ListNode* reverseList(ListNode* head)
{
	if(head==NULL || head->next == NULL)
		return head;

	ListNode* p = head->next;
	ListNode* newhead = reverseList(head->next);
	p->next = head;
	head->next = NULL;
	return newhead;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

	ListNode* q = new ListNode(2);
	p->next = q;
	p=q;

	q = new ListNode(6);
	p->next = q;
	p = q;

	q = new ListNode(3);
	p->next = q;
	p = q;

	q = new ListNode(4);
	p->next = q;
	p = q;

	q = new ListNode(5);
	p->next = q;
	p = q;

	q = new ListNode(6);
	p->next = q;
	p = q;

	ListNode* result = reverseList(head);
	p=result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}

	return 0;
}
