#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
#include<set>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

struct Treenode
{
    Treenode(Treenode* nil): val(make_pair(0,0)), parent(nil), left(nil), right(nil)
    {}

    Treenode(pair<int,int> x, Treenode* nil): val(x), parent(nil), left(nil), right(nil)
    {}

    pair<int,int> val;
    Treenode* parent;
    Treenode *left, *right;
};

class BST
{
    public:
        Treenode *nil;
        BST()
        {
            nil = new Treenode(nil);
            root = nil;
        }

        void insert(Treenode* z)
        {
            Treenode* y=nil;
            Treenode* x=root;
            while(x!=nil)
            {
                y=x;
                 if(z->val.first<=x->val.first)
                    x=x->left;
                else
                    x=x->right;
                ++y->val.second;
            }
            z->parent=y;
            if(y==nil)
                root=z;
            else if(z->val.first<=y->val.first)
                y->left = z;
            else
                y->right = z;
        }

        int find(Treenode* z)
        {
            int result=0;
            Treenode *x=root;
            while(x!=nil && x!=z)
            {
                if(z->val.first <= x->val.first)
                    x=x->left;
                else
                {
                    result += x->left->val.second+1;
                    x=x->right;
                }
            }
            if(x==nil)
                result = 0;
            else
                result += x->left->val.second;
            return result;
        }

    private:
        Treenode *root;
};

/*struct Treenode
{
    Treenode(Treenode* nil): val(make_pair(0,0)), color('R'), parent(nil), left(nil), right(nil)
    {}

    Treenode(pair<int,int> x, Treenode* nil): val(x), color('R'), parent(nil), left(nil), right(nil)
    {}

    pair<int,int> val;
    char color;
    Treenode* parent;
    Treenode *left, *right;
};

class RB_tree
{
    public:
        Treenode *nil;
        RB_tree()
        {
            nil = new Treenode(nil);
            nil->color = 'B';
            root = nil;
        }

        void insert(Treenode* z)
        {
            Treenode* y=nil;
            Treenode* x=root;
            while(x!=nil)
            {
                y=x;
                 if(z->val.first<=x->val.first)
                    x=x->left;
                else
                    x=x->right;
                ++y->val.second;
            }
            z->parent=y;
            if(y==nil)
                root=z;
            else if(z->val.first<=y->val.first)
                y->left = z;
            else
                y->right = z;

            insert_fixup(z);
        }

        int find(Treenode* z)
        {
            int result=0;
            Treenode *x=root;
            while(x!=nil && x!=z)
            {
                if(z->val.first <= x->val.first)
                    x=x->left;
                else
                {
                    result += x->left->val.second+1;
                    x=x->right;
                }
            }
            if(x==nil)
                result = 0;
            else
                result += x->left->val.second;
            return result;
        }

    private:
        Treenode *root;
        void insert_fixup(Treenode* z)
        {
            while(z->parent->color == 'R')
            {
                if(z->parent == z->parent->parent->left)
                {
                    Treenode* y=z->parent->parent->right;
                    if(y->color == 'R')
                    {
                        z->parent->color = 'B';
                        y->color = 'B';
                        z->parent->parent->color = 'R';
                        z=z->parent->parent;
                    }
                    else
                    {
                        if(z == z->parent->right)
                        {
                            z=z->parent;
                            left_rotate(z);
                        }
                        z->parent->color = 'B';
                        z->parent->parent->color = 'R';
                        right_rotate(z->parent->parent);
                    }
                }
                else
                {
                    Treenode* y=z->parent->parent->right;
                    if(y->color == 'R')
                    {
                        z->parent->color = 'B';
                        y->color = 'B';
                        z->parent->parent->color = 'R';
                        z=z->parent->parent;
                    }
                    else
                    {
                        if(z == z->parent->left)
                        {
                            z=z->parent;
                            right_rotate(z);
                        }
                        z->parent->color = 'B';
                        z->parent->parent->color = 'R';
                        left_rotate(z->parent->parent);
                    }
                }
            }
            root->color = 'B';
        }

        void right_rotate(Treenode* x)
        {
            Treenode* y = x->left;
            x->left = y->right;
            if(y->right!=nil)
                y->right->parent = x;
            y->parent = x->parent;
            if(x->parent == nil)
                root=y;
            else if(x==x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->right = x;
            x->parent = y;
            x->val.second = 1 + x->left->val.second + x->right->val.second;
            y->val.second = 1 + y->left->val.second + y->right->val.second;
        }

        void left_rotate(Treenode* x)
        {
            Treenode* y = x->right;
            x->right = y->left;
            if(y->left != nil)
                y->left->parent=x;
            y->parent = x->parent;
            if(x->parent == nil)
                root=y;
            else if(x==x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
            x->val.second = 1 + x->left->val.second + x->right->val.second;
            y->val.second = 1 + y->left->val.second + y->right->val.second;
        }
};*/

vector<int> countSmaller(vector<int>& nums)
{
    vector<int> result(nums.size(),0);
    BST tree;

    for(int i=nums.size()-1; i>=0; --i)
    {
        Treenode* z = new Treenode(make_pair(nums[i],1),tree.nil);
        tree.insert(z);
        result[i] = tree.find(z);
    }
    return result;
}

int main()
{
    vector<int> nums {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << "\t";
    cout << endl;
    return 0;
}
