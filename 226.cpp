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

/*
TreeNode* invertTree(TreeNode* root)
{
	if(root == NULL)
		return NULL;

	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invertTree(root->right);
	return root;
}
*/

TreeNode* invertTree(TreeNode* root)
{
	deque<TreeNode*> queue;

	if(root != NULL)
		queue.push_back(root);

	while(!queue.empty())
	{
		TreeNode *cur = queue.front();
		queue.pop_front();
		TreeNode *tmp = cur->left;
		cur->left = cur->right;
		cur->right = tmp;

		if(cur->left)
			queue.push_back(cur->left);
		if(cur->right)
			queue.push_back(cur->right);
	}

	return root;
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(4);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	q = new TreeNode(7);
	p->right = q;

	p = p->left;

	q = new TreeNode(1);
	p->left = q;

	q = new TreeNode(3);
	p->right = q;

	p = root->right;

	q = new TreeNode(6);
	p->left = q;

	q = new TreeNode(9);
	p->right = q;

	TreeNode* result = invertTree(root);
	cout << result->left->val << endl;
	cout << result->left->left->val << endl;
	return 0;
}
