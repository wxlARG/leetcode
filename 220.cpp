#include"common.h"
using namespace std;

bool containsNearbyAlmostDuplicate_solution1(vector<int>& nums, int k, int t) {
    if(t<0) return false;
    set<long long> cache;
    for(int i=0; i<nums.size(); ++i) {
        if(i>k) cache.erase(nums[i-k-1]);
        if(cache.find(nums[i])!=cache.end()) return true;
        auto cur=cache.insert(nums[i]).first;
        auto next=cur;
        ++next;
        if(cur!=cache.begin()) {
            auto prev = cur;
            --prev;
            if(*cur-*prev<=t) return true;
        }
        if(next!=cache.end() && *next-*cur<=t) return true;
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.empty() || t<0) return false;
    unordered_map<long long, long long> buckets;
    long long min_val=*min_element(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); ++i) {
        if(i>k) buckets.erase((nums[i-k-1]-min_val)/((long long)t+1));
        long long bucket_num=(nums[i]-min_val)/((long long)t+1);
        if(buckets.find(bucket_num)!=buckets.end()) return true;
        buckets[bucket_num]=nums[i];
        if(buckets.find(bucket_num+1)!=buckets.end() && buckets[bucket_num+1]-nums[i]<=t) return true;
        if(buckets.find(bucket_num-1)!=buckets.end() && nums[i]-buckets[bucket_num-1]<=t) return true;
    }
    return false;
}

int main() {
    vector<int> nums={2147483647,-2147483647};
    cout << containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;
}
