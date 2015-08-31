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

int func(TreeNode* root, int& result)
{
	int left=0,right=0;

	if(root->left != NULL && (left=func(root->left, result))<0)
		left = 0;

	if(root->right != NULL && (right=func(root->right, result))<0)
		right = 0;

	if(result < left+right+root->val)
		result = left+right+root->val;
	return root->val+max(left,right);
}

int maxPathSum(TreeNode *root)
{
	if(root == NULL)
		return 0;
	int result = INT_MIN;
	func(root,result);
	return result;
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

	int result = maxPathSum(root);
	cout << result << endl;
	return 0;
}
