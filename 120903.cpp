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

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if(p==NULL && q==NULL) 
		return true;

	if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) 
		return false;

	if(p->val != q->val)
		return false;

	if(!isSameTree(p->left, q->left))
		return false;

	if(!isSameTree(p->right, q->right))
		return false;

	return true;
}

int main()
{
	TreeNode* root1 = NULL;
	TreeNode* p = new TreeNode(4);
	root1 = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	TreeNode* root2 = NULL;
	p = new TreeNode(4);
	root2 = p;

	q = new TreeNode(2);
	p->left = q;

	bool result = isSameTree(root1, root2);
	cout << result << endl;
	return 0;
}
