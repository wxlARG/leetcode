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

int minSubArrayLen(int s, vector<int>& nums) {
    vector<int> sum(nums.size()+1, 0);
    int res=INT_MAX;
    for(int i=0; i<nums.size(); ++i) sum[i+1]+=sum[i]+nums[i];
    for(int i=1; i<sum.size(); ++i) {
        int target=sum[i]-s;
        auto it=upper_bound(sum.begin(), sum.begin()+i, target);
        if(it!=sum.begin()) res=min(res, int(sum.begin()+i-it+1));
    }
    return res==INT_MAX? 0: res;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
	cout << minSubArrayLen(7, nums) << endl;
}
