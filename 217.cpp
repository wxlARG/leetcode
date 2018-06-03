#include"common.h"
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> cache;
    for(auto &num: nums) {
        if(cache.find(num)!=cache.end()) return true;
        cache.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums={1,1,1,3,3,4,3,2,4,2};
    cout << containsDuplicate(nums) << endl;
}
