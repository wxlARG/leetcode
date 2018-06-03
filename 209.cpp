#include"common.h"
using namespace std;

int minSubArrayLen_solution1(int s, vector<int>& nums) {
    int res=INT_MAX, sum=0;
    for(int start=0, end=0; end<nums.size(); ++end) {
        sum += nums[end];
        if(sum>=s) res = min(res, end-start+1);
        while(sum>=s) {
            res = min(res, end-start+1);
            sum-=nums[start++];
        }
    }
    return res==INT_MAX? 0: res;
}

int helper(int s, vector<int>& nums, int start, int end) {
    if(start==end) {
        if(nums[start]>=s) return 1;
        else return INT_MAX;
    }
    int res=INT_MAX;
    int mid=start+(end-start)/2;
    int lres=helper(s, nums, start, mid);
    int rres=helper(s, nums, mid+1, end);
    res=min(lres, rres);
    int head=mid, tail=mid+1;
    for(int lsum=nums[head]; head>start && lsum<s; ) lsum+=nums[--head];
    for(int rsum=nums[tail]; tail<end && rsum<s; ) rsum+=nums[++tail];
    for(int i=head, j=head, sum=0; j<=tail; ++j) {
        sum += nums[j];
        if(sum>=s) res = min(res, j-i+1);
        while(sum>=s) {
            res = min(res, j-i+1);
            sum-=nums[i++];
        }
    } 
    return res;
}

int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size()==0) return 0;
    int res=helper(s, nums, 0, nums.size()-1);
    return res==INT_MAX? 0: res;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
	cout << minSubArrayLen(7, nums) << endl;
}
