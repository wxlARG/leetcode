#include"common.h"
using namespace std;

int minPatches(vector<int>& nums, int n) {
    int64_t cur=1;
    int pos=0, res=0;
    while(cur<=n) {
        if(pos<nums.size() && cur>=nums[pos]) {
            cur+=nums[pos++];
        } else {
            ++res;
            cur+=cur;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3};
    cout << minPatches(nums, 6) << endl;
}
