#include"common.h"
using namespace std;

int maximumGap_solution1(vector<int>& nums) {
    vector<int> sorted_arr(nums.size(), 0);
    for(int i=0; i<32; ++i) {
        int zero=0, one=0;
        for(auto &v: nums) {
            if((v & (1<<i)) == 0) ++zero;
            else ++one;
        }
        one += zero;
        for(int j=nums.size()-1; j>=0; --j) {
            if((nums[j] & (1<<i)) == 0) sorted_arr[--zero]=nums[j];
            else sorted_arr[--one]=nums[j];
        }
        nums.swap(sorted_arr);
    }
    int res=0;
    for(int i=1; i<nums.size(); ++i) res = max(res, nums[i]-nums[i-1]);
    return res;
}

int maximumGap(vector<int>& nums) {
    if(nums.size()<=1) return 0;
    int min_val=INT_MAX, max_val=INT_MIN;
    for(auto &num: nums) {
        min_val=min(min_val, num);
        max_val=max(max_val, num);
    }
    int bucket_num=nums.size()-1;
    int interval=(max_val-min_val)/bucket_num+1;
    vector<pair<bool, pair<int, int>>> buckets(bucket_num, {false, {0, 0}});
    for(auto &num: nums) {
        int pos=(num-min_val)/interval;
        if(buckets[pos].first==false) {
            buckets[pos].first=true;
            buckets[pos].second = {num, num};
        } else {
            buckets[pos].second.first=min(buckets[pos].second.first, num);
            buckets[pos].second.second=max(buckets[pos].second.second, num);
        }
    }
    int res=0, last_max=buckets[0].second.first;
    for(auto &p: buckets) {
        if(!p.first) continue;
        res=max(res, p.second.first-last_max);
        res=max(res, p.second.second-p.second.first);
        last_max=p.second.second;
    }
    return res;
}

int main() {
    //vector<int> nums={3,9,6,1};
    vector<int> nums={1,1,1,1};
    cout << maximumGap(nums) << endl;
}
