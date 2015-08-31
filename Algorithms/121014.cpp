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

void func(TreeNode* root, TreeNode*& lastnode)
{
	lastnode = root;
	if(root->left != NULL)
		func(root->left,lastnode);

	if(root->right != NULL)
	{
		lastnode->left = root->right;
		root->right = NULL;
		func(lastnode->left,lastnode);
	}
}

void flatten(TreeNode *root)
{
	if(root == NULL)
		return;

	TreeNode* lastnode = root;
	func(root,lastnode);

	for(TreeNode* p=root; p!=NULL; p=p->right)
	{
		p->right = p->left;
		p->left=NULL;
	}
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(1);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	p=p->left;
	q = new TreeNode(3);
	p->left = q;

	q = new TreeNode(4);
	p->right = q;

	p=root;
	q = new TreeNode(5);
	p->right = q;

	p=p->right;
	q = new TreeNode(6);
	p->right = q;

	flatten(root);
	for(p=root; p!=NULL; p=p->right)
		cout << p->val << endl;
	return 0;
}
