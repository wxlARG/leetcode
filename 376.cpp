#include"common.h"
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if(nums.size()<=1) return nums.size();
    int res=0, less=0, large=0;
    for(int i=1; i<nums.size(); ++i) {
        if(nums[i]>nums[i-1]) large=less+1;
        else if(nums[i]<nums[i-1]) less=large+1;
        res=max(large, less)+1;
    }
    return res;
}

int main() {
    vector<int> nums={1,7,4,9,2,5};
    cout << wiggleMaxLength(nums) << endl;
}
