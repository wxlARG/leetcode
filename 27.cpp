#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int pos = 0;
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]==val) continue;
        nums[pos++] = nums[i];
    }
    return pos;
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    auto res = removeElement(nums, 3);
    for(int i=0; i<res; ++i)
        cout << nums[i] << "\t";
    cout << endl;
}
