#include<iostream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;
class NumArray {
    public:
        struct TreeNode
        {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode():val(0),left(NULL),right(NULL)
            {}
        };

        NumArray(vector<int> &nums){
            this->nums = nums;
            if(nums.size()==0)
                root=NULL;
            else
                root = func(nums,0,nums.size()-1);
        }

        TreeNode* func(vector<int> &nums, int start, int end)
        {
            if(start == end)
            {
                TreeNode *p = new TreeNode();
                p->val = nums[start];
                return p;
            }

            TreeNode *p = new TreeNode();
            int mid = start + (end-start)/2;
            p->left = func(nums,start,mid);
            p->right = func(nums,mid+1,end);
            p->val = p->left->val+p->right->val;
            return p;
        }
        
        void update(int i, int val) {
            int diff = nums[i] - val;
            nums[i]=val;
            int start=0,end=nums.size()-1;
            TreeNode *p = root;
            while(start != end)
            {
                p->val -= diff;
                int mid = start + (end-start)/2;
                if(i<=mid)
                {
                    p=p->left;
                    end = mid;
                }
                else
                {
                    p=p->right;
                    start = mid+1;
                }
            }
            p->val = val;
        }

        int range(TreeNode *p, int i, int j, int start, int end)
        {
            if(i<=start && j>=end)
                return p->val;

            int mid = start + (end-start)/2;
            if(j<=mid)
                return range(p->left,i,j,start,mid);
            else if(i>mid)
                return range(p->right,i,j,mid+1,end);
            else
                return range(p->left,i,mid,start,mid)+range(p->right,mid+1,j,mid+1,end);

        }

        int sumRange(int i, int j) {
            return range(root,i,j,0,nums.size()-1);
        }
    private:
        TreeNode* root;
        vector<int> nums;
};

int main()
{
    int a[] = {7,2,7,2,0};
    vector<int> nums;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

    NumArray numArray(nums);
    numArray.update(4, 6);
    numArray.update(0, 2);
    numArray.update(0, 9);
    cout << numArray.sumRange(4, 4) << endl;
    numArray.update(3, 8);
    cout << numArray.sumRange(0, 4) << endl;
    numArray.update(4, 1);
    cout << numArray.sumRange(0, 3) << endl;
    cout << numArray.sumRange(0, 4) << endl;
    return 0;
}
