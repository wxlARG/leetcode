#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int res = INT_MAX;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); ++i) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int t = target-nums[i];
        for(int s=i+1, e=nums.size()-1; s<e;) {
            if(res == INT_MAX || abs(nums[s] + nums[e] - t) < abs(res - nums[i] - t))
                res = nums[s] + nums[e] + nums[i];
            if(nums[s] + nums[e] < t) ++s;
            else if(nums[s] + nums[e] > t) --e;
            else return target;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 1, 1, 0};
    cout << threeSumClosest(nums, 100) << endl;
}
