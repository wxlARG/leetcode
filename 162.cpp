#include"common.h"
using namespace std;

int findPeakElement_solution1(vector<int>& nums) {
    for(int i=0; i<nums.size(); ++i) {
        int prev=i>0? nums[i-1]: INT_MIN;
        int next=i<nums.size()-1? nums[i+1]: INT_MIN;
        if(nums[i]>prev && nums[i]>next) return i;
    }
    return 0;
}

int findPeakElement(vector<int>& nums) {
    int start=0, end=nums.size()-1;
    while(start<=end) {
        int mid=start+(end-start)/2;
        int prev=mid>0? nums[mid-1]: INT_MIN;
        int next=mid<nums.size()-1? nums[mid+1]: INT_MIN;
        if(nums[mid]>prev && nums[mid]>next) return mid;
        if(nums[mid]>=prev) start=mid+1;
        else end=mid-1;
    }
    return 0;
}

int main() {
    vector<int> nums={1, 2, 3, 1};
    //vector<int> nums={1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums) << endl;
}
