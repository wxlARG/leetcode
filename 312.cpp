#include"common.h"
using namespace std;

int maxCoins(vector<int>& nums) {
    if(nums.size()==0) return 0;
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    for(int len=1; len<=nums.size(); ++len) {
        for(int start=0; start<=nums.size()-len; ++start) {
            int end=start+len-1;
            for(int k=start; k<=end; ++k) {
                int left=k-1>=start? dp[start][k-1]: 0;
                int right=k+1<=end? dp[k+1][end]: 0;
                int mid=(start>0? nums[start-1]: 1)*nums[k]*(end<nums.size()-1? nums[end+1]: 1);
                dp[start][end]=max(dp[start][end], left+right+mid);
            }
        }
    }
    return dp[0][nums.size()-1];
}

int main() {
    vector<int> nums={3,1,5,8};
    cout << maxCoins(nums) << endl;
}
