#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void helper_solution1(vector<int>& nums, vector<vector<int>>& res, vector<int>& cache, vector<bool>& flag) {
    if(cache.size()==nums.size()) {
        res.push_back(cache);
        return;
    }
    for(int i=0; i<nums.size(); ++i) {
        if(!flag[i]) {
            flag[i] = true;
            cache.push_back(nums[i]);
            helper_solution1(nums, res, cache, flag);
            cache.pop_back();
            flag[i] = false;
            while(i<nums.size()-1 && nums[i] == nums[i+1]) ++i;
        }
    }
}

vector<vector<int>> permuteUnique_solution1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cache;
    vector<bool> flag(nums.size(), false);
    helper_solution1(nums, res, cache, flag);
    return res;
}

void helper(vector<int>& nums, int begin, vector<vector<int>>& res) {
    if(begin==nums.size()) {
        res.push_back(nums);
        return;
    }
    unordered_set<int> cache;
    for(int i=begin; i<nums.size(); ++i) {
        if(cache.find(nums[i])!=cache.end()) continue;
        swap(nums[begin], nums[i]);
        helper(nums, begin+1, res);
        swap(nums[begin], nums[i]);
        cache.insert(nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    helper(nums, 0, res);
    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    auto res = permuteUnique(nums);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
