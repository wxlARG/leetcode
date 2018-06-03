#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int pos = 0;
    for(int i=1; i<nums.size(); ++i) {
        if(nums[i]==nums[pos]) continue;
        nums[++pos] = nums[i];
    }
    return ++pos;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4};
    auto res = removeDuplicates(nums);
    for(int i=0; i<res; ++i)
        cout << nums[i] << "\t";
    cout << endl;
}
