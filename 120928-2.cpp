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

vector<vector<int> > levelOrder(TreeNode *root)
{
	vector<vector<int> > result;

	if(root == NULL)
		return result;

	deque<TreeNode*> queue;

	queue.push_back(root);
	while(!queue.empty())
	{
		TreeNode* nextstart = NULL;
		vector<int> cache;

		while(!queue.empty() && queue.front() != nextstart)
		{
			TreeNode* node = queue.front();
			queue.pop_front();
			cache.push_back(node->val);

			if(node->left != NULL)
			{
				queue.push_back(node->left);
				if(nextstart == NULL)
					nextstart = node->left;
			}

			if(node->right != NULL)
			{
				queue.push_back(node->right);
				if(nextstart == NULL)
					nextstart = node->right;
			}
		}

		if(cache.size() != 0)
			result.push_back(cache);
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

	vector<vector<int> > result = levelOrder(root);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
