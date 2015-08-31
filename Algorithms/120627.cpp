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

ListNode *reverseBetween(ListNode *head, int m, int n)
{
	ListNode* p=NULL, *q=head;

	for(int i=m-1; i>0; --i)
	{
		p=q;
		q=q->next;
	}

	ListNode* cache=p, *cachenext=q;
	p=q;
	q=q->next;

	for(int i=0; i<n-m; ++i)
	{
		ListNode* tmp = q->next;
		q->next = p;
		p=q;
		q=tmp;
	}

	cachenext->next = q;
	if(cache!=NULL)
		cache->next = p;
	else
		head = p;

	return head;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

	ListNode* q = new ListNode(2);
	p->next = q;
	p=p->next;

	q = new ListNode(3);
	p->next = q;
	p=p->next;

	q = new ListNode(4);
	p->next = q;
	p=p->next;

	q = new ListNode(5);
	p->next = q;
	p=p->next;

	ListNode* result = reverseBetween(head,2,4);
	p = result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	return 0;
}
