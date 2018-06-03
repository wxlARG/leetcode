#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper(vector<int>& nums, int start, vector<int>& cache, vector<vector<int>>& res) {
    if(start == nums.size()) {
        res.push_back(cache);
        return;
    }
    int next_start = start+1;
    while(next_start!=nums.size() && nums[next_start] == nums[start]) ++next_start;
    helper(nums, next_start, cache, res);
    for(int i=start; i!=next_start; ++i) {
        cache.push_back(nums[i]);
        helper(nums, next_start, cache, res);
    }
    for(int i=start; i!=next_start; ++i) cache.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>> res;
     vector<int> cache;
     sort(nums.begin(), nums.end());
     helper(nums, 0, cache, res);
     return res;
}

int main() {
    //vector<int> nums = {1,2,2};
    vector<int> nums = {4, 4, 4, 1, 4};
    auto res = subsetsWithDup(nums);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
