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

ListNode *insertionSortList(ListNode *head)
{
	if(head == NULL)
		return NULL;

	ListNode* newhead = head;
	ListNode* q=head, *p=head->next;
	while(p!=NULL)
	{
		ListNode* r = p->next;
		q->next = r;
		ListNode* tail=q;

		ListNode* tmp2 = NULL;
		ListNode* tmp1 = NULL;
		for(tmp1=newhead; tmp1!=r; tmp1=tmp1->next)
		{
			if(p->val > tmp1->val)
			{
				tmp2 = tmp1;
				continue;
			}

			if(tmp2==NULL)
			{
				p->next = newhead;
				newhead = p;
			}
			else
			{
				tmp2->next=p;
				p->next=tmp1;
			}
			break;
		}

		if(tmp1 == r)
		{
			tail = p;
			p->next = tmp2->next;
			tmp2->next = p;
		}

		q=tail;
		p=r;
	}

	return newhead;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;

//	ListNode* q = new ListNode(2);
//	p->next = q;
//	p=q;

//	q = new ListNode(3);
//	p->next = q;
//	p = q;

	ListNode* result = insertionSortList(head);
	p=result;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}

	return 0;
}
