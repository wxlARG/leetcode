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

ListNode *reverseKGroup(ListNode *head, int k)
{
	if(head == NULL)
		return NULL;

	ListNode* p = head;
	ListNode* flag = head;
	ListNode* innerHead = NULL;

	for(int i=k-1; i>0 && flag!=NULL; --i)
		flag = flag->next;

	while(flag != NULL)
	{
		innerHead = p;
		ListNode* q = p->next;
		flag = flag->next;
		for(int i=k-1; i>0; --i)
		{
			ListNode* r = q->next;
			q->next = p;
			if(p == head)
				head = q;
			p=q;
			q=r;

			if(flag != NULL)
				flag = flag->next;
		}

		if(flag != NULL)
			innerHead->next = flag;
		p = q;
	}

	if(innerHead != NULL)
		innerHead->next = p;

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

	p = reverseKGroup(head,3);
	while(p != NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
