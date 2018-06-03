#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<vector<int>> threeSum_solution1(vector<int>& nums) {
    vector<vector<int>> res;
    unordered_map<int, int> map;
    for(auto &v : nums)
        ++map[v];
    sort(nums.begin(), nums.end());
    for(int i=0; i<int(nums.size())-2; ++i) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<int(nums.size())-1; ++j) {
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int last = 0-nums[i]-nums[j];
            if(last<nums[j]) break;
            --map[nums[i]], --map[nums[j]];
            if(map[last] != 0) 
                res.push_back({nums[i], nums[j], last});
            ++map[nums[i]], ++map[nums[j]];
        }
    }
    return res;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); ++i) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int t = -nums[i];
        for(int s=i+1, e=nums.size()-1; s<e;) {
            if(nums[s] + nums[e] < t) ++s;
            else if(nums[s] + nums[e] > t) --e;
            else {
                res.push_back({nums[i], nums[s], nums[e]});
                do {++s;} while(nums[s-1] == nums[s] && s<e);
                do {--e;} while(nums[e] == nums[e+1] && s<e);
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-2, 0, 0, 2, 2};
    auto res = threeSum(nums);
    for(auto &vec : res) {
        for(auto &v : vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
