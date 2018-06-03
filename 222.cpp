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

int func(TreeNode *root, int start, int end, int h)
{
	if(start > end)
		return -1;

	int mid = start + (end-start)/2;
	int height = -1;
	TreeNode* p=root;

	while(p!=NULL)
	{
		++height;
		if(height == h) break;
		if(mid & 1<<(h-height-1))
			p=p->right;
		else
			p=p->left;
	}

	if(height == h)
	{
		int tmp = func(root,mid+1,end,h);
		if(tmp == -1)
			return mid+1;
		return tmp;
	}
	else
	{
		int tmp = func(root,start,mid-1,h);
		if(tmp == -1)
			return mid;
		return tmp;
	}
}

int countNodes(TreeNode* root)
{
	int result = 0;
	int h = -1;
	for(TreeNode *p=root; p!=NULL; p=p->left)
		++h;

	if(h<0)
		return 0;

	result = (1<<h)-1;

	result += func(root,0,(1<<h)-1,h);

	return result;
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(1);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

/*	q = new TreeNode(3);
	p->right = q;

	p = p->left;

	q = new TreeNode(4);
	p->left = q;

	q = new TreeNode(5);
	p->right = q;

	p = root->right;

	q = new TreeNode(6);
	p->left = q;

	q = new TreeNode(7);
	p->right = q;*/

	int result = countNodes(root);
	cout << result << endl;
	return 0;
}
