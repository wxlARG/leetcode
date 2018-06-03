#include"common.h"
using namespace std;

int findMin(vector<int>& nums) {
    int start=0, end=nums.size()-1, res=INT_MAX;
    while(start<=end) {
        int mid=start+(end-start)/2;
        if(nums[mid]>nums[start]) {
            res=min(res, nums[start]);
            start=mid+1;
        } else if(nums[mid]<nums[start]) {
            res=min(res, nums[mid]);
            end=mid-1;
        } else {
            for(int i=start; i<=end; ++i) res=min(res, nums[i]);
            break;
        }
    }
    return res;
}

int main() {
    vector<int> nums={2, 3};
    cout << findMin(nums) << endl;
}
