#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool canJump(vector<int>& nums) {
    for(int start=0, end=0; end<nums.size()-1;) {
        int new_end=end;
        for(int i=start; i<=end; ++i) {
            new_end = max(new_end, nums[i]+i);
        }
        start=end+1;
        end = new_end;
        if(start>end) return false;
    }
    return true;
}

int main() {
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) << endl;
}
