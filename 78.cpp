#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper(int start, vector<int>& nums, vector<int>& cache, vector<vector<int>>& res) {
    res.push_back(cache);
    for(int i=start; i<nums.size(); ++i) {
        cache.push_back(nums[i]);
        helper(i+1, nums, cache, res);
        cache.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cache;
    helper(0, nums, cache, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = subsets(nums);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
