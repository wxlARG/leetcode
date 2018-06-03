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

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
	RandomListNode* p = head;
	while(p!=NULL)
	{
		RandomListNode* q = new RandomListNode(p->label);
		q->next = p->next;
		p->next = q;
		p = q->next;
	}

	p = head;
	while(p!=NULL)
	{
		RandomListNode* q = p->next;
		if(p->random != NULL)
			q->random = p->random->next;
		p = q->next;
	}

	p = head;
	RandomListNode* head1 = NULL;
	RandomListNode* cur = NULL;

	while(p!=NULL)
	{
		RandomListNode* q = p->next;
		p->next = q->next;
		p = p->next;

		if(head1 == NULL)
			head1 = q;
		else
			cur->next = q;

		cur = q;
	}

	return head1;
}

int main()
{
	RandomListNode* head = NULL;
	RandomListNode* cur = NULL;
	RandomListNode* plist = new RandomListNode(1);
	head = plist;
	cur = plist;

	plist = new RandomListNode(2);
	cur->next = plist;
	cur = cur->next;

	plist = new RandomListNode(3);
	cur->next = plist;
	cur = cur->next;

	head->random = cur;

	plist = new RandomListNode(4);
	cur->next = plist;
	cur = cur->next;

	RandomListNode* head1 = copyRandomList(head);
	cout << head1->random->label << endl;
	return 0;
}
