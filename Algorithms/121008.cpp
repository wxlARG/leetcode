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

bool func(TreeNode* root, int& depth)
{
	if(root == NULL)
	{
		depth = 0;
		return true;
	}

	int leftdepth;
	int rightdepth;

	if(!func(root->left, leftdepth))
		return false;

	if(!func(root->right, rightdepth))
		return false;

	if(abs(leftdepth-rightdepth) > 1)
		return false;

	depth = max(leftdepth,rightdepth) + 1;
	return true;
}

bool isBalanced(TreeNode *root)
{
	int depth;
	return func(root, depth);
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(4);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	q = new TreeNode(3);
	p->right = q;

	bool result = isBalanced(root);
	cout << result << endl;
	return 0;
}
