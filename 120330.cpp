#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode* p = l1;
	ListNode* q = l2;

	ListNode* head = NULL;
	ListNode* cur = NULL;

	while(p!=NULL && q!=NULL)
	{
		ListNode* tmp = NULL;
		if(p->val <= q->val)
		{
			tmp = p;
			p=p->next;
		}
		else
		{
			tmp = q;
			q=q->next;
		}

		if(head == NULL)
			head = cur = tmp;
		else
		{
			cur->next = tmp;
			cur = cur->next;
		}
	}

	if(p!=NULL)
	{
		if(head == NULL)
			head = cur = p;
		else
			cur->next = p;
	}

	if(q!=NULL)
	{
		if(head == NULL)
			head = cur = q;
		else
			cur->next = q;
	}

	return head;
}

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* p = l1;

	p->next = new ListNode(3);
	p=p->next;

	p->next = new ListNode(5);
	p=p->next;

	ListNode* l2 = new ListNode(2);
	p = l2;

	p->next = new ListNode(4);
	p=p->next;

	ListNode* result = mergeTwoLists(l1,l2);

	p=result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	return 0;
}
