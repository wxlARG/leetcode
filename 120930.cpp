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

TreeNode* func(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend)
{
	if(prestart > preend)
		return NULL;

	int target = preorder[prestart];
	int size = 0;
	for(int i=instart; inorder[i]!=target; ++i)
		++size;

	TreeNode* root = new TreeNode(target);
	root->left = func(preorder, prestart+1, prestart+size, inorder, instart, instart+size-1);
	root->right = func(preorder, prestart+size+1, preend, inorder, instart+size+1, inend);
	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	return func(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

int main()
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);

	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);

	TreeNode* result = buildTree(preorder,inorder);
	cout << result->right->val << endl;
	return 0;
}
