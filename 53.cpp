#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxSubArray_solution1(vector<int>& nums) {
    int res=INT_MIN, val=0;
    for(int i=0; i<nums.size(); ++i) {
        res = max(nums[i], res);
        if(val+nums[i]<=0) {
            val=0;
        } else {
            val += nums[i];
            res = max(val, res);
        }
    }
    return res;
}

int helper(vector<int>& nums, int& head, int& tail, int& sum, int start, int end) {
    if(start==end) {
        head=tail=sum=nums[start];
        return nums[start];
    }
    vector<int> cache(6, 0);
    int mid=start+(end-start)/2;
    int max1 = helper(nums, cache[0], cache[1], cache[2], start, mid);
    int max2 = helper(nums, cache[3], cache[4], cache[5], mid+1, end);
    sum = cache[2]+cache[5];
    head = max(cache[0], cache[2]+cache[3]);
    tail = max(cache[4], cache[5]+cache[1]);
    return max(max(max1, max2), cache[1]+cache[3]);
}

int maxSubArray(vector<int>& nums) {
    vector<int> cache(3, 0);
    return helper(nums, cache[0], cache[1], cache[2], 0, nums.size()-1);
}

int main() {
    vector<int> nums = {-5,8,-5,1,1,-3,5,5,-3,-3,6,4,-7,-4,-8,0,-1,-6};
    cout << maxSubArray(nums) << endl;
}
