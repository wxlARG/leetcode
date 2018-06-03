#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int jump(vector<int>& nums) {
    int res=0;
    for(int start=0, pos=0; pos<nums.size()-1;) {
        int next_start = pos+1;
        int next_pos = pos+1;
        for(int i=start; i<=pos; ++i) {
            if(nums[i]+i>next_pos) {
                next_pos = nums[i]+i;
            }
        }
        start = next_start;
        pos = next_pos;
        ++res;
    }
    return res;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums) << endl;
}
