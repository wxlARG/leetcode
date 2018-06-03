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

void func(TreeNode* root, int& result)
{
	result += root->val;
	if(root->left==NULL && root->right==NULL)
		return;

	result*=10;
	if(root->left==NULL)
		func(root->right,result);
	else if(root->right==NULL)
		func(root->left,result);
	else
	{
		int tmp = result;
		func(root->left,result);
		func(root->right,tmp);
		result+=tmp;
	}
}

int sumNumbers(TreeNode *root)
{
	if(root == NULL)
		return 0;

	int result = 0;
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

	int result = sumNumbers(root);
	cout << result << endl;
	return 0;
}
