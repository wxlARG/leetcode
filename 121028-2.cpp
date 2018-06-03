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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
	TreeLinkNode* listhead = root;
	TreeLinkNode* newhead=NULL, *p=NULL, *q=NULL;

	while(listhead != NULL)
	{
		q=listhead;
		while(q!=NULL)
		{
			if(q->left != NULL)
			{
				if(newhead == NULL)
					newhead = q->left;
				else
					p->next = q->left;
				p=q->left;
			}

			if(q->right != NULL)
			{
				if(newhead == NULL)
					newhead = q->right;
				else
					p->next = q->right;
				p=q->right;
			}
			q=q->next;
		}
		listhead = newhead;
		newhead=p=NULL;
	}
}

int main()
{
	TreeLinkNode* root = NULL;
	TreeLinkNode* p = new TreeLinkNode(1);
	root = p;

	TreeLinkNode* q = new TreeLinkNode(2);
	p->left = q;

	q = new TreeLinkNode(3);
	p->right = q;

	p = root->left;
	q = new TreeLinkNode(4);
	p->left = q;

	q = new TreeLinkNode(5);
	p->right = q;

	p=root->right;
	q = new TreeLinkNode(7);
	p->right = q;

	connect(root);

	p = root->left->left;
	while(p!=NULL)
	{
		cout << p->val << endl;
		p=p->next;
	}
	return 0;
}
