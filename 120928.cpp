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

vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int> > result;

	if(root == NULL)
		return result;

	deque<TreeNode*> stack1;
	deque<TreeNode*> stack2;
	vector<int> cache;

	deque<TreeNode*>* pcur = &stack1;
	deque<TreeNode*>* pnext = &stack2;

	int flag = 0;
	pcur->push_back(root);

	while(!pcur->empty())
	{
		TreeNode* node = pcur->back();
		pcur->pop_back();
		cache.push_back(node->val);

		if((flag & 1) == 0)
		{
			if(node->left != NULL)
				pnext->push_back(node->left);

			if(node->right != NULL)
				pnext->push_back(node->right);
		}
		else
		{
			if(node->right != NULL)
				pnext->push_back(node->right);

			if(node->left != NULL)
				pnext->push_back(node->left);
		}

		if(pcur->empty())
		{
			swap(pcur,pnext);
			result.push_back(cache);
			cache.clear();
			++flag;
		}
	}

	return result;
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

	vector<vector<int> > result = zigzagLevelOrder(root);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
