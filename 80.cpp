#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int pos=0;
    for(int i=0; i<nums.size(); ++i) {
        if(pos>1 && nums[pos-2]==nums[i]) continue;
        nums[pos++] = nums[i];
    }
    return pos;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout << removeDuplicates(nums) << endl;
}
