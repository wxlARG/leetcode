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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	ListNode* r = NULL;
	ListNode* p = head;
	ListNode* q = p;

	while(n-- != 0)
		q = q->next;

	while(q != NULL)
	{
		r = p;
		p = p->next;
		q = q->next;
	}

	if(r == NULL)
		return head->next;
	
	r->next = p->next;
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

	head = removeNthFromEnd(head,2);

	p = head;
	while(p!= NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
