#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

void sortColors(vector<int>& nums) {
    int start=0, end=nums.size()-1;
    for(int i=0; i<=end; ++i) {
        if(nums[i]==0) {
            swap(nums[i], nums[start++]);
        } else if(nums[i]==2) {
            swap(nums[i--], nums[end--]);
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 1, 0, 1, 2};
    //vector<int> nums = {2,2,0,0,2,0,2,1,0};
    sortColors(nums);
    for(auto v: nums) {
        cout << v << "\t";
    }
    cout << endl;
}
