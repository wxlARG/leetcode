#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int res=-1;
    int start=0, end=nums.size()-1;
    while(start<=end) {
        int m = start+(end-start)/2;
        if(target==nums[m]) {
            return m;
        } else if(target>nums[m]) {
            res = m+1;
            start = m+1;
        } else {
            res=m;
            end = m-1;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 3) << endl;
}
