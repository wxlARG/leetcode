#include<iostream>
#include<sstream>
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

void func(vector<string> &result, string &s, TreeNode* root)
{
    stringstream ss;
    ss<<root->val;
    string tmp = ss.str();
    s+=tmp;
    if(root->left == NULL && root->right == NULL)
        result.push_back(s);
    else
        s+="->";

    if(root->left != NULL)
        func(result,s,root->left);

    if(root->right != NULL)
        func(result,s,root->right);

    if(root->left != NULL || root->right != NULL)
        for(int i=0; i<2; ++i)
            s.pop_back();

    for(int i=0; i<tmp.size(); ++i)
        s.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    string s;

    if(root==NULL)
        return result;

    func(result,s,root);
    return result;
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* p = new TreeNode(1);
	root = p;

	TreeNode* q = new TreeNode(-20);
	p->left = q;

	q = new TreeNode(-3);
	p->right = q;

	p = p->left;

	q = new TreeNode(5);
	p->right = q;

	vector<string> result = binaryTreePaths(root);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;
	return 0;
}
