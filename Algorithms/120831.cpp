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

bool func(TreeNode *root, int& maxval, int& minval)
{
	if(root->left==NULL && root->right==NULL)
	{
		maxval = root->val;
		minval = root->val;
		return true;
	}

	int leftmin = INT_MAX;
	int leftmax = INT_MIN;
	int rightmin = INT_MAX;
	int rightmax = INT_MIN;
	bool result = true;

	if(root->left != NULL)
	{
		result = func(root->left, leftmax, leftmin);
		if(!result || root->val <= leftmax)
			return false;
		minval = leftmin;
		maxval = root->val;
	}

	if(root->right != NULL)
	{
		result = func(root->right, rightmax, rightmin);
		if(!result || root->val >= rightmin)
			return false;
		maxval = rightmax;
		if(minval > root->val)
			minval = root->val;
	}

	return true;
}

bool isValidBST(TreeNode *root)
{
	if(root == NULL)
		return true;

	int maxval = INT_MIN;
	int minval = INT_MAX;
	return func(root,maxval,minval);
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(1);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	q = new TreeNode(3);
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
	p->right = q;

	bool result = isValidBST(root);
	cout << result << endl;
	return 0;
}
