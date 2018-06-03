#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cache, vector<bool>& flag) {
    if(cache.size()==nums.size()) {
        res.push_back(cache);
        return;
    }
    for(int i=0; i<nums.size(); ++i) {
        if(!flag[i]) {
            flag[i] = true;
            cache.push_back(nums[i]);
            helper(nums, res, cache, flag);
            cache.pop_back();
            flag[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cache;
    vector<bool> flag(nums.size(), false);
    helper(nums, res, cache, flag);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = permute(nums);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
