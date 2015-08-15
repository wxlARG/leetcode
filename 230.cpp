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

void func(TreeNode* root, TreeNode*& target, int& cur, int k)
{
	if(root==NULL || target!=NULL)
		return;

	func(root->left,target,cur,k);
	++cur;
	if(cur==k)
		target = root;
	func(root->right,target,cur,k);
}

int kthSmallest(TreeNode* root, int k)
{
	int cur=0;
	TreeNode* target = NULL;

	func(root,target,cur,k);
	return target->val;
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

	int result = kthSmallest(root,7);
	cout << result << endl;
	return 0;
}
