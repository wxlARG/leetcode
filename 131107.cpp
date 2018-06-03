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

vector<int> postorderTraversal(TreeNode *root)
{
	deque<TreeNode*> stack;
	vector<int> result;

	if(root == NULL)
		return result;

	stack.push_back(root);
	TreeNode* lastnode = root;

	while(!stack.empty())
	{
		TreeNode* curnode = stack.back();

		if(curnode == NULL)
		{
			lastnode = curnode;
			stack.pop_back();
		}
		else if(curnode->right == lastnode)
		{
			lastnode = curnode;
			stack.pop_back();
			result.push_back(curnode->val);
		}
		else
		{
			stack.push_back(curnode->right);
			if(curnode->left != NULL)
				stack.push_back(curnode->left);
		}
	}

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

	p = p->left;

	q = new TreeNode(4);
	p->left = q;

	q = new TreeNode(5);
	p->right = q;

	p = root->right;

	q = new TreeNode(6);
	p->left = q;

	q = new TreeNode(7);
	p->right = q;

	vector<int> result = postorderTraversal(root);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
