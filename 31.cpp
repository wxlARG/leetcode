#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pos = -1;
    for(int i=nums.size()-2; i>=0; --i) {
        if(nums[i]<nums[i+1]) {
            pos = i;
            break;
        }
    }
    if(pos == -1)
        reverse(nums.begin(), nums.end());
    else {
        for(int i=nums.size()-1; i>=0; --i) {
            if(nums[pos]<nums[i]) {
                swap(nums[pos], nums[i]);
                reverse(nums.begin()+pos+1, nums.end());
                break;
            }
        }
    }
}

int main() {
    vector<int> nums = {3, 1, 2};
    //vector<int> nums = {2, 3, 1};
    //vector<int> nums = {1, 3, 2};
    nextPermutation(nums);
    for(auto &v: nums)
        cout << v << "\t";
    cout << endl;
}
