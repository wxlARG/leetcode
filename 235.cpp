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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(p->val > q->val)
        return lowestCommonAncestor(root, q, p);

    if(p->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else if(q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return root;
}

int main()
{
	TreeNode* root = NULL;
    TreeNode *p1=NULL, *q1=NULL;
	TreeNode* p = new TreeNode(6);
	root = p;

	TreeNode* q = new TreeNode(2);
    p1=q;
	p->left = q;

	q = new TreeNode(8);
	p->right = q;

	p = p->left;

	q = new TreeNode(0);
	p->left = q;

	q = new TreeNode(4);
    q1=q;
	p->right = q;

	p = root->right;

	q = new TreeNode(7);
	p->left = q;

	q = new TreeNode(9);
	p->right = q;

	TreeNode* result = lowestCommonAncestor(root,p1,q1);
	cout << result->val << endl;
	return 0;
}
