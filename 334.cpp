#include"common.h"
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    pair<int, int> cache={INT_MAX, INT_MAX};
    for(auto v: nums) {
        if(v>cache.second) return true;
        if(v<=cache.first) cache.first=v;
        else if(v<=cache.second) cache.second=v;
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << increasingTriplet(nums) << endl;
}
