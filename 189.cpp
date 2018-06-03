#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if(k==0) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 1);
    for(auto &v: nums) cout << v << "\t";
    cout << endl;
}
