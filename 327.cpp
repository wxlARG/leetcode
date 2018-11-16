#include"common.h"
using namespace std;

int countRangeSum_solution1(vector<int>& nums, int lower, int upper) {
    multiset<int64_t> t;
    int res=0;
    int64_t nl=lower, nu=upper;
    for(int64_t i=0, last=0; i<nums.size(); ++i) {
        last+=nums[i];
        t.insert(last);
    }
    for(int64_t i=0, last=0; i<nums.size(); ++i) {
        auto l=t.lower_bound(nl);
        auto u=t.upper_bound(nu);
        res += distance(l, u);
        nl+=nums[i], nu+=nums[i];
        last+=nums[i];
        t.erase(t.find(last));
    }
    return res;
}

int countRangeSum_solution2(vector<int>& nums, int lower, int upper) {
    int64_t mini=numeric_limits<int64_t>::max(), maxi=numeric_limits<int64_t>::min();
    int64_t nl=lower, nu=upper, res=0;
    vector<int64_t> sums;
    unordered_map<int64_t, int> bit;
    for(int64_t v: nums) sums.push_back((sums.empty()? 0: sums.back())+v);
    for(auto v: sums) mini=min(mini, v);
    for(auto& v: sums) {
        v-=(mini-1);
        maxi=max(maxi, v);
    }
    nl-=(mini-1), nu-=(mini-1);
    for(auto v: sums) {
        for(auto u=v; u<=maxi; u+=(u&-u)) ++bit[u];
    }
    for(int i=0; i<nums.size(); ++i) {
        int c1=0, c2=0;
        if(!(nu<1 || nl>maxi)) {
            for(auto u=nl-1; u>0; u-=(u&-u)) c1+=bit[u];
            for(auto u=min(nu, maxi); u>0; u-=(u&-u)) c2+=bit[u];
            res+=c2-c1;
        }
        for(auto u=sums[i]; u<=maxi; u+=(u&-u)) --bit[u];
        nl+=nums[i], nu+=nums[i];
    }
    return res;
}

int helper(vector<int64_t>& sums, int start, int end, int lower, int upper) {
    if(start>end) return 0;
    if(start==end) return (sums[start]>=lower && sums[start]<=upper? 1: 0);
    int mid=start+(end-start)/2, res=0;
    res+=helper(sums, start, mid, lower, upper);
    res+=helper(sums, mid+1, end, lower, upper);
    int s=mid+1, e=mid+1;
    for(int i=start; i<=mid; ++i) {
        while(s<=end && sums[s]-sums[i]<lower) ++s;
        while(e<=end && sums[e]-sums[i]<=upper) ++e;
        res+=e-s;
    }
    inplace_merge(sums.begin()+start, sums.begin()+mid+1, sums.begin()+end+1);
    return res;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<int64_t> sums={0};
    for(auto v: nums) sums.push_back(sums.back()+v);
    return helper(sums, 1, sums.size()-1, lower, upper);
}

int main() {
    vector<int> nums = {-2, 5, -1};
    cout << countRangeSum(nums, -2, 2) << endl;
    //vector<int> nums = {-2147483647,0,0,0};
    //cout << countRangeSum(nums, -2775, 2201) << endl;
}
