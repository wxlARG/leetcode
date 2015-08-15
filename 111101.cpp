#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<string.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* head = NULL;
	ListNode* p = head;
	int flag = 0;

	while(p1 != NULL && p2 != NULL)
	{
		int num1 = p1->val;
		int num2 = p2->val;

		int num = num1 + num2 + flag;

		ListNode* tmp = new ListNode(num%10);
		flag = num/10;

		if(head == NULL)
			head = tmp;
		else
			p->next = tmp;
		p = tmp;

		p1 = p1->next;
		p2 = p2->next;
	}

	while(p1 != NULL)
	{
		int num1 = p1->val;
		int num2 = 0;

		int num = num1 + num2 + flag;

		ListNode* tmp = new ListNode(num%10);
		flag = num/10;

		if(head == NULL)
			head = tmp;
		else
			p->next = tmp;
		p = tmp;

		p1 = p1->next;
	}

	while(p2 != NULL)
	{
		int num1 = 0;
		int num2 = p2->val;

		int num = num1 + num2 + flag;

		ListNode* tmp = new ListNode(num%10);
		flag = num/10;

		if(head == NULL)
			head = tmp;
		else
			p->next = tmp;
		p = tmp;

		p2 = p2->next;
	}

	if(flag != 0)
	{
		ListNode* tmp = new ListNode(flag%10);

		if(head == NULL)
			head = tmp;
		else
			p->next = tmp;
		p = tmp;
	}

	return head;
}

int main()
{
	ListNode* l1 = new ListNode(2);
	ListNode* pos = l1;
	ListNode* tmp = new ListNode(4);
	pos->next = tmp;
	pos = tmp;
	tmp = new ListNode(3);
	pos->next = tmp;
	pos = tmp;

	ListNode* l2 = new ListNode(5);
	pos = l2;
	tmp = new ListNode(6);
	pos->next = tmp;
	pos = tmp;
	tmp = new ListNode(4);
	pos->next = tmp;
	pos = tmp;

	ListNode* head = addTwoNumbers(l1, l2);
	for(ListNode* p=head;p!=NULL;p=p->next)
	{
		cout <<p->val<<endl;
	}
	return 0;
}


