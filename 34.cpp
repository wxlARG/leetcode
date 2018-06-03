#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int lower_bound=-1, upper_bound=-1;
    int start=0, end=nums.size()-1;
    while(start<=end) {
        int m = start+(end-start)/2;
        if(target>nums[m]) 
            start = m+1;
        else {
            if(target==nums[m])
                lower_bound = m;
            end = m-1;
        }
    }

    start=0, end=nums.size()-1;
    while(start<=end) {
        int m = start+(end-start)/2;
        if(target<nums[m])
            end = m-1;
        else {
            if(target==nums[m])
                upper_bound = m;
            start = m+1;
        }
    }
    return {lower_bound, upper_bound};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto res = searchRange(nums, 8);
    for(auto &v: res)
        cout << v << "\t";
    cout << endl;
}
