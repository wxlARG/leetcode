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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
	if(head == NULL)
		return NULL;

	ListNode* p = NULL;
	ListNode* q = head;
	ListNode* r = head;

	while(r != NULL && r->next != NULL)
	{
		p = q;
		q = q->next;
		r = r->next->next;
	}

	TreeNode* root = new TreeNode(q->val);

	if(p == NULL)
		root->left = NULL;
	else
	{
		p->next = NULL;
		root->left = sortedListToBST(head);
	}

	root->right = sortedListToBST(q->next);

	return root;
}

int main()
{
	ListNode* head = NULL;
	ListNode* cur = NULL;
	ListNode* plist = new ListNode(1);
	head = plist;
	cur = plist;

	plist = new ListNode(2);
	cur->next = plist;

	TreeNode* root = sortedListToBST(head);
	cout << root->left->val << endl;
	return 0;
}
