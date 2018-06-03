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

/*class MedianFinder {
    public:
        MedianFinder()
        {
            make_heap(minheap.begin(),minheap.end(),greater<int>());
            make_heap(maxheap.begin(),maxheap.end());
        }

        void addNum(int num) 
        {
            int minsize = minheap.size();
            int maxsize = maxheap.size();
            if(minsize+maxsize==0 || num<=maxheap.front())
            {
                maxheap.push_back(num);
                push_heap(maxheap.begin(),maxheap.end());
                ++maxsize;
            }
            else
            {
                minheap.push_back(num);
                push_heap(minheap.begin(),minheap.end(),greater<int>());
                ++minsize;
            }

            if(maxsize-minsize>1)
            {
                pop_heap(maxheap.begin(),maxheap.end());
                minheap.push_back(maxheap.back());
                push_heap(minheap.begin(),minheap.end(),greater<int>());
                maxheap.pop_back();
            }
            else if(maxsize-minsize<0)
            {
                pop_heap(minheap.begin(),minheap.end(),greater<int>());
                maxheap.push_back(minheap.back());
                push_heap(maxheap.begin(),maxheap.end());
                minheap.pop_back();
            }
        }

        double findMedian() 
        {
            if(minheap.size()==maxheap.size())
                return (minheap.front()+maxheap.front())/2.0;
            else
                return maxheap.front();
        }

    private:
        vector<int> minheap;
        vector<int> maxheap;
};*/

struct Treenode
{
    Treenode(Treenode* nil): val(0), color('R'), parent(nil), left(nil), right(nil)
    {}

    Treenode(int x, Treenode* nil): val(x), color('R'), parent(nil), left(nil), right(nil)
    {}

    int val;
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
                if(z->val<=x->val)
                    x=x->left;
                else
                    x=x->right;
            }
            z->parent=y;
            if(y==nil)
                root=z;
            else if(z->val<=y->val)
                y->left = z;
            else
                y->right = z;

            insert_fixup(z);
        }

        Treenode* pre(Treenode* x)
        {
            if(x->left!=nil)
            {
                Treenode* y=x->left;
                while(y->right!=nil)
                    y=y->right;
                return y;
            }

            Treenode* y = x->parent;
            while(y!=nil && x==y->left)
            {
                x=y;
                y=y->parent;
            }
            return y;
        }

        Treenode* next(Treenode* x)
        {
            if(x->right!=nil)
            {
                Treenode* y=x->right;
                while(y->left!=nil)
                    y=y->left;
                return y;
            }

            Treenode* y = x->parent;
            while(y!=nil && x==y->right)
            {
                x=y;
                y=y->parent;
            }
            return y;
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
        }
};

class MedianFinder {
    public:
        MedianFinder():total(0),mid(NULL){}
        void addNum(int num) 
        {
            Treenode* z = new Treenode(num,rb_tree.nil);
            rb_tree.insert(z);

            if(total == 0)
                mid = z;
            else if(num<=mid->val)
            {
                if((total & 1)!=0)
                    mid=rb_tree.pre(mid);
            }
            else
            {
                if((total & 1)==0)
                    mid=rb_tree.next(mid);
            }
            ++total;
        }

        double findMedian() 
        {
            if((total & 1)==0)
            {
//                cout<<mid->val<<endl;
//                cout<<rb_tree.next(mid)->val<<endl;
                return (mid->val+rb_tree.next(mid)->val)/2.0;
            }
            else
                return mid->val;
        }

    private:
        RB_tree rb_tree;
        int total;
        Treenode* mid;
};

int main()
{
    MedianFinder mf;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(10);
    cout << mf.findMedian() << endl;
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(5);
    cout << mf.findMedian() << endl;
    mf.addNum(0);
    cout << mf.findMedian() << endl;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    mf.addNum(1);
    cout << mf.findMedian() << endl;
    mf.addNum(0);
    cout << mf.findMedian() << endl;
    mf.addNum(0);
    cout << mf.findMedian() << endl;
        
/*    mf.addNum(0);
    mf.addNum(0);
    cout << mf.findMedian() << endl;*/
    return 0;
}
