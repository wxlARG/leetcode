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

TreeNode* func(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend)
{
	if(poststart > postend)
		return NULL;

	int target = postorder[postend];
	int size = 0;
	for(int i=instart; inorder[i]!=target; ++i)
		++size;

	TreeNode* root = new TreeNode(target);
	root->left = func(inorder, instart, instart+size-1, postorder, poststart, poststart+size-1);
	root->right = func(inorder, instart+size+1, inend, postorder, poststart+size, postend-1);
	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
	return func(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

int main()
{
	vector<int> inorder;
	inorder.push_back(2);
	inorder.push_back(1);

	vector<int> postorder;
	postorder.push_back(2);
	postorder.push_back(1);

	TreeNode* result = buildTree(inorder,postorder);
	cout << result->left->val << endl;
	return 0;
}
