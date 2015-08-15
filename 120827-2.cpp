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

void func(int start, int end, vector<TreeNode *>& result)
{
	if(start > end)
	{
		result.push_back(NULL);
		return;
	}

	for(int i=start; i<=end; ++i)
	{
		vector<TreeNode *> left, right;
		func(start,i-1,left);
		func(i+1,end,right);

		for(int j=0; j<left.size(); ++j)
		{
			for(int k=0; k<right.size(); ++k)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left[j];
				root->right = right[k];
				result.push_back(root);
			}
		}
	}
}

vector<TreeNode *> generateTrees(int n)
{
	vector<TreeNode *> result;
	func(1,n,result);
	return result;
}

int main()
{
	vector<TreeNode *> result = generateTrees(3);
	for(int i=0; i<result.size(); ++i)
		cout << result[i]->val << endl;
	return 0;
}
