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
    if(root==NULL)
        return NULL;

    bool flag = 0;
    if(root==p || root==q)
        flag=1;

    TreeNode* ltmp=lowestCommonAncestor(root->left,p,q);
    if(ltmp!=NULL && flag)
        return root;

    TreeNode* rtmp=lowestCommonAncestor(root->right,p,q);
    if(rtmp!=NULL && flag)
        return root;

    if(ltmp!=NULL && rtmp!=NULL)
        return root;
    else if(flag)
        return root;
    return ltmp==NULL ? rtmp : ltmp;
}

int main()
{
	TreeNode* root = NULL;
    TreeNode *p1=NULL, *q1=NULL;
	TreeNode* p = new TreeNode(3);
	root = p;

	TreeNode* q = new TreeNode(5);
    p1=q;
	p->left = q;

	q = new TreeNode(1);
    q1=q;
	p->right = q;

	p = p->left;

	q = new TreeNode(6);
	p->left = q;

	q = new TreeNode(2);
	p->right = q;

	p = root->right;

	q = new TreeNode(0);
	p->left = q;

	q = new TreeNode(8);
	p->right = q;

	TreeNode* result = lowestCommonAncestor(root,p1,q1);
	cout << result->val << endl;
	return 0;
}
