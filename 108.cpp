#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

TreeNode* helper(vector<int>& nums, int start, int end) {
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    auto root = new TreeNode(nums[mid]);
    root->left = helper(nums, start, mid-1);
    root->right = helper(nums, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    auto res = sortedArrayToBST(nums);
    cout << print_tree(res) << endl;
}
