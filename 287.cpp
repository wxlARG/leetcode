#include"common.h"
using namespace std;

int findDuplicate_solution1(vector<int>& nums) {
    int start=1, end=nums.size()-1, res=0;
    while(start<end) {
        int mid=start+(end-start)/2, count=0;
        for(auto& v: nums) if(v<=mid) ++count;
        if(count<=mid) start=mid+1;
        else end=mid;
    }
    return start;
}

int findDuplicate(vector<int>& nums) {
    int slow=0, fast=0;
    do {
        slow=nums[slow];
        fast=nums[nums[fast]];
    } while(slow!=fast);
    slow=0;
    while(slow!=fast) {
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

int main() {
    //vector<int> nums = {8,1,1,1,2,7,4,3,1,1};
    vector<int> nums = {4,3,1,4,2};
    cout << findDuplicate(nums) << endl;
}
