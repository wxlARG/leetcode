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

void func(vector<vector<int> >& result, vector<int>& tmp, TreeNode* root, int sum)
{
	if(root == NULL)
		return;

	if(root->left==NULL && root->right==NULL)
	{
		tmp.push_back(root->val);
		if(sum==root->val)
			result.push_back(tmp);
		tmp.pop_back();
		return;
	}

	tmp.push_back(root->val);
	if(root->left != NULL)
		func(result,tmp,root->left,sum-root->val);

	if(root->right != NULL)
		func(result,tmp,root->right,sum-root->val);
	tmp.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
	vector<vector<int> > result;
	vector<int> tmp;
	func(result,tmp,root,sum);
	return result;
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

	q = new TreeNode(5);
	p->left = q;

	q = new TreeNode(1);
	p->right = q;

	vector<vector<int> > result = pathSum(root,22);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
