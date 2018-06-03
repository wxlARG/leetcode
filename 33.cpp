#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int search(vector<int>& nums, int target) {
    int start=0, end=nums.size()-1;
    while(start<=end) {
        int m=start+(end-start)/2;
        if(target==nums[m]) return m;
        if(nums[m]<nums[end]) {
            if(target>=nums[m] && target<=nums[end])
                start = m+1;
            else
                end = m-1;
        } else {
            if(target>=nums[0] && target<=nums[m])
                end = m-1;
            else
                start=m+1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 100) << endl;
}
