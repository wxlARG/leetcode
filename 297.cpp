#include<iostream>
#include<sstream>
#include<vector>
#include<list>
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        if(root == NULL)
            return result;

        list<TreeNode*> cache;
        cache.push_back(root);
        while(!cache.empty())
        {
            TreeNode* tmp = cache.front();
            cache.pop_front();
            if(tmp==NULL)
                result += "N,";
            else
            {
                stringstream ss;
                ss << tmp->val;
                string s;
                ss >>s;
                result += s+",";
                cache.push_back(tmp->left);
                cache.push_back(tmp->right);
            }
        }
        result.back()=0;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;

        int pos = 0;
        bool flag = 0;
        list<TreeNode*> cache;
        TreeNode* root  = new TreeNode(helper(data,pos,flag));
        cache.push_back(root);
        while(!cache.empty())
        {
            TreeNode* tmp = cache.front();
            cache.pop_front();
            int val = helper(data,pos,flag);
            if(!flag)
            {
                TreeNode* left = new TreeNode(val);
                tmp->left = left;
                cache.push_back(left);
            }
            flag=0;

            val = helper(data,pos,flag);
            if(!flag)
            {
                TreeNode* right = new TreeNode(val);
                tmp->right = right;
                cache.push_back(right);
            }
            flag=0;
        }
        return root;
    }
private:
    int helper(string &data, int &start, bool &flag)
    {
        int val;
        int pos = data.find(",",start);
        if(pos == string::npos)
            pos = data.size();
        string tmp(data,start,pos-start);
        start = pos+1;
        if(tmp[0] == 'N')
        {
            flag = 1;
            return -1;
        }
        stringstream ss;
        ss<<tmp;
        ss>>val;
        return val;
    }
};

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

    Codec codec;
    cout << codec.serialize(root) << endl;
    TreeNode* root1 = codec.deserialize(codec.serialize(root));
    cout << root1->left->right->val << endl;
	return 0;
}
