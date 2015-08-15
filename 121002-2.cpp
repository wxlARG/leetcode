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

TreeNode *func(vector<int> &num, int start, int end)
{
	if(start > end)
		return NULL;

	int mid = start + (end-start)/2;
	TreeNode* root = new TreeNode(num[mid]);
	root->left = func(num,start,mid-1);
	root->right = func(num,mid+1,end);
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num)
{
	return func(num,0,num.size()-1);
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);

	TreeNode* root = sortedArrayToBST(num);
	cout << root->right->val << endl;
	return 0;
}
