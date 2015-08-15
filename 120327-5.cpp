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

ListNode *rotateRight(ListNode *head, int k)
{
	if(head == NULL)
		return NULL;

	int num = 0;
	ListNode* p = head;
	ListNode* q = head;

	for(;p!=NULL; p=p->next)
		++num;

	k = k%num;

	if(k==0)
		return head;

	p = head;
	for(int i=0; i<k; ++i)
		q = q->next;

	while(q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}

	ListNode* tmp = head;
	head = p->next;
	p->next = NULL;
	q->next = tmp;
	return head;
}

int main()
{
	ListNode* p = new ListNode(5);
	ListNode* head = p;

	p = new ListNode(4);
	p->next = head;
	head = p;

	p = new ListNode(3);
	p->next = head;
	head = p;

	p = new ListNode(2);
	p->next = head;
	head = p;

	p = new ListNode(1);
	p->next = head;
	head = p;

	p = rotateRight(head,2);
	while(p != NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
