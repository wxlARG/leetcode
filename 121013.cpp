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

bool hasPathSum(TreeNode *root, int sum)
{
	if(root == NULL)
		return false;

	if(root->left == NULL && root->right == NULL)
		if(sum == root->val)
			return true;
		else
			return false;

	if(root->left != NULL && hasPathSum(root->left,sum-root->val))
		return true;

	if(root->right != NULL && hasPathSum(root->right,sum-root->val))
		return true;

	return false;
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(5);
	root = p;

	TreeNode* q = new TreeNode(4);
	p->left = q;

	q = new TreeNode(8);
	p->right = q;

	p = root->left;

	q = new TreeNode(11);
	p->left = q;
	p=q;

	q = new TreeNode(7);
	p->left = q;

	q = new TreeNode(2);
	p->right = q;

	p=root->right;

	q = new TreeNode(13);
	p->left = q;

	q = new TreeNode(4);
	p->right = q;
	p=q;

	q = new TreeNode(1);
	p->right = q;

	bool result = hasPathSum(root,22);
	cout << result << endl;
	return 0;
}
