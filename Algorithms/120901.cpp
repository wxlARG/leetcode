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

void func(TreeNode *root, vector<TreeNode*>& result, int preval, int postval)
{
	if(root == NULL)
		return;

	func(root->left, result, preval, root->val);

	int nodepreval = preval;
	int nodepostval = postval;

	TreeNode* p1 = root;
	TreeNode* q1 = p1->left;

	while(q1 != NULL)
	{
		p1 = q1;
		q1 = q1->right;
	}

	if(p1!=root)
		nodepreval = p1->val;

	TreeNode* p2 = root;
	TreeNode* q2 = p2->right;

	while(q2 != NULL)
	{
		p2 = q2;
		q2 = q2->left;
	}

	if(p2!=root)
		nodepostval = p2->val;

	if(root->val > nodepreval && root->val > nodepostval && result[0] == NULL)
		result[0] = root;

	if(root->val < nodepreval && root->val < nodepostval)
		result[1] = root;

	func(root->right, result, root->val, postval);
}

void recoverTree(TreeNode *root)
{
	if(root == NULL)
		return;

	vector<TreeNode*> result;

	result.push_back(NULL);
	result.push_back(NULL);

	func(root, result, INT_MIN, INT_MAX);
	swap(result[0]->val, result[1]->val);
}

int main()
{
/*	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(4);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	q = new TreeNode(3);
	p->right = q;

	p = p->left;

	q = new TreeNode(1);
	p->left = q;

	q = new TreeNode(6);
	p->right = q;

	p = root->right;

	q = new TreeNode(5);
	p->left = q;

	q = new TreeNode(7);
	p->right = q;*/

	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(2);
	root = p;

	TreeNode* q = new TreeNode(1);
	p->right = q;

//	cout << root->left->right->val <<endl;
	cout << root->right->val <<endl;

	recoverTree(root);

//	cout << root->left->right->val <<endl;
	cout << root->right->val <<endl;

	return 0;
}
