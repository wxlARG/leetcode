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

/*
bool func(TreeNode* left, TreeNode* right)
{
	if(left == NULL && right == NULL)
		return true;

	if(left == NULL || right == NULL)
		return false;

	if(left->val != right->val)
		return false;

	if(!func(left->left, right->right))
		return false;

	if(!func(left->right, right->left))
		return false;

	return true;
}

bool isSymmetric(TreeNode *root)
{
	if(root == NULL)
		return true;

	return func(root->left, root->right);
}
*/

bool isSymmetric(TreeNode *root)
{
	if(root == NULL)
		return true;

	deque<TreeNode*> stack1;
	deque<TreeNode*> stack2;
	vector<TreeNode*> cache;

	deque<TreeNode*>* pcur = &stack1;
	deque<TreeNode*>* pnext = &stack2;

	pcur->push_back(root);

	while(!pcur->empty())
	{
		TreeNode* node = pcur->front();
		cache.push_back(node);
		pcur->pop_front();

		if(node != NULL)
		{
			pnext->push_back(node->left);
			pnext->push_back(node->right);
		}

		if(pcur->empty())
		{
			swap(pcur,pnext);

			int start = 0;
			int end = cache.size()-1;
			while(start < end)
			{
				if((cache[start] == NULL && cache[end] != NULL) || (cache[start] != NULL && cache[end] == NULL))
					return false;
				else if(cache[start] != NULL && cache[end] != NULL && cache[start]->val != cache[end]->val)
					return false;

				++start;
				--end;
			}
			cache.clear();
		}
	}

	return true;
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(4);
	root = p;

	TreeNode* q = new TreeNode(2);
	p->left = q;

	q = new TreeNode(2);
	p->right = q;

	bool result = isSymmetric(root);
	cout << result << endl;
	return 0;
}
