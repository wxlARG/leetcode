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

int minDepth(TreeNode *root)
{
	if(root == NULL)
		return 0;

	int left = minDepth(root->left);
	int right = minDepth(root->right);

	if(left == 0 && right == 0)
		return 1;
	else if(left == 0)
		return right+1;
	else if(right == 0)
		return left+1;
	else
		return min(left,right)+1;
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

	int result = minDepth(root);
	cout << result << endl;
	return 0;
}
