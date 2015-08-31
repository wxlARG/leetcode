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

ListNode *detectCycle(ListNode *head)
{
	ListNode* p=head, *q=head;
	while(q!=NULL && q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(p==q)
		{
			q=head;
			while(p!=q)
			{
				p=p->next;
				q=q->next;
			}
			return p;
		}
	}
	return NULL;
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

	q = new ListNode(4);
	p->next = q;
	p = q;

	q = new ListNode(5);
	p->next = q;
	p = q;

	q->next = head->next;

	ListNode* result = detectCycle(head);
	cout << result->val << endl;

	return 0;
}
