#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool search_solution1(vector<int>& nums, int target) {
    for(auto &v: nums) {
        if(v==target) return true;
    }
    return false;
}

bool search(vector<int>& nums, int target) {
    int start=0, end=nums.size()-1;
    while(start<=end) {
        int mid = start+(end-start)/2;
        if(target==nums[mid]) return true;
        if(nums[mid]>nums[end]) {
            if(target>=nums[start] && target<nums[mid]) end=mid-1;
            else start=mid+1;
        } else if(nums[mid]<nums[end]) {
            if(target<=nums[end] && target>nums[mid]) start=mid+1;
            else end=mid-1;
        } else {
            --end;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 3) << endl;
}
