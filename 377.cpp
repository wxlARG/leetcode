#include"common.h"
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> cache(target+1, 0);
    cache[0]=1;
    for(int i=1; i<=target; ++i) {
        for(auto v: nums) cache[i]+=(i>=v? cache[i-v]: 0);
    }
    return cache.back();
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << combinationSum4(nums, 4) << endl;
}
