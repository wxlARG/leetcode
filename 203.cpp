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

ListNode* removeElements(ListNode* head, int val)
{
	ListNode *p = head;
	ListNode *q = NULL;

	while(p!=NULL)
	{
		if(p->val==val)
		{
			if(q==NULL)
				head = p->next;
			else
				q->next = p->next;
		}
		else
			q=p;

		p=p->next;
	}
	return head;
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

	ListNode* result = removeElements(head,6);
	p=result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}

	return 0;
}
