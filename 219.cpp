#include"common.h"
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> cache;
    for(int i=0; i<nums.size(); ++i) {
        if(cache.find(nums[i])==cache.end()) cache[nums[i]]=i;
        else if(i-cache[nums[i]]<=k) return true;
        else cache[nums[i]]=i;
    }
    return false;
}

int main() {
    //vector<int> nums={1,2,3,1,2,3};
    vector<int> nums={1,2,3,1};
    cout << containsNearbyDuplicate(nums, 3) << endl;
}
