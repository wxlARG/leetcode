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
	ListNode* pos = head;
	ListNode* cur = head;

	while(cur != NULL)
	{
		if(pos->val != cur->val)
		{
			pos->next = cur;
			pos = cur;
		}
		cur = cur->next;
	}
	if(pos!=NULL)
		pos->next = NULL;
	return head;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

	ListNode* q = new ListNode(1);
	p->next = q;
	p=p->next;

	q = new ListNode(2);
	p->next = q;
	p=p->next;

	q = new ListNode(3);
	p->next = q;
	p=p->next;

	q = new ListNode(3);
	p->next = q;
	p=p->next;

	ListNode* result = deleteDuplicates(head);
	p = result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	return 0;
}
