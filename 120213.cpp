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

ListNode* exactMin(vector<ListNode*>& heap)
{
	int size = heap.size();
	ListNode* result = heap[0];
	swap(heap[0],heap[size-1]);
	heap.pop_back();

	int p = 0;
	int left = 2*p+1;
	int right = 2*p+2;

	size = heap.size();
	while(left < size || right < size)
	{
		int minPos = p;
		if(left < size && heap[left]->val < heap[minPos]->val)
			minPos = left;
		if(right < size && heap[right]->val < heap[minPos]->val)
			minPos = right;

		if(minPos == p)
			break;

		swap(heap[p],heap[minPos]);
		p = minPos;
		left = 2*p+1;
		right = 2*p+2;
	}
	return result;
}

void insert(vector<ListNode*>& heap, ListNode* node)
{
	if(node == NULL)
		return;

	heap.push_back(node);
	int pos = heap.size()-1;
	int parent = (pos-1)/2;

	while(parent >= 0 && heap[pos]->val < heap[parent]->val)
	{
		swap(heap[pos],heap[parent]);
		pos = parent;
		parent = (pos-1)/2;
	}
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	ListNode* head = NULL;
	ListNode* p = head;

	vector<ListNode*> heap;

	for(int i=0; i<lists.size(); ++i)
		insert(heap, lists[i]);

	while(heap.size() != 0)
	{
		ListNode* node = exactMin(heap);

		if(head == NULL)
		{
			head = node;
			p = head;
		}
		else
		{
			p->next = node;
			p = p->next;
		}

		insert(heap, node->next);
	}

	if(p != NULL)
		p->next = NULL;

	return head;
}

int main()
{
	vector<ListNode *> lists;

	ListNode* p = new ListNode(1);
	ListNode* head = p;

	p = new ListNode(-1);
	p->next = head;
	head = p;

	lists.push_back(head);

	p = new ListNode(4);
	head = p;

	p = new ListNode(1);
	p->next = head;
	head = p;

	p = new ListNode(-3);
	p->next = head;
	head = p;

	lists.push_back(head);

	p = new ListNode(2);
	head = p;

	p = new ListNode(0);
	p->next = head;
	head = p;

	p = new ListNode(-1);
	p->next = head;
	head = p;

	p = new ListNode(-2);
	p->next = head;
	head = p;

	lists.push_back(head);

	p = mergeKLists(lists);
	while(p != NULL)
	{
		cout << p->val << endl;
		p = p->next;
	}
	return 0;
}
