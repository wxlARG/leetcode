#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

vector<vector<int>> fourSum_solution1(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); ++i) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<nums.size(); ++j) {
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int t = target-nums[i]-nums[j];
            for(int s=j+1, e=nums.size()-1; s<e;) {
                if(nums[s] + nums[e] < t) ++s;
                else if(nums[s] + nums[e] > t) --e;
                else {
                    res.push_back({nums[i], nums[j], nums[s], nums[e]});
                    do {++s;} while(nums[s-1] == nums[s] && s<e);
                    do {--e;} while(nums[e] == nums[e+1] && s<e);
                }
            }
        }
    }
    return res;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    unordered_map<int, vector<pair<int, int>>> tsc;
    set<tuple<int, int, int, int>> cache;
    for(int i=0; i<nums.size(); ++i) {
        for(int j=i+1; j<nums.size(); ++j) 
            tsc[nums[i]+nums[j]].push_back({i, j});
    }
    for(auto &kv: tsc) {
        if(kv.first>target/2) continue;
        auto it = tsc.find(target-kv.first);
        if(it==tsc.end()) continue;
        for(auto &v1: kv.second) {
            for(auto &v2: it->second) {
                if(v1.first != v2.first && v1.first != v2.second && v1.second != v2.first && v1.second != v2.second) {
                    vector<int> t = {nums[v1.first], nums[v1.second], nums[v2.first], nums[v2.second]};
                    sort(t.begin(), t.end());
                    if(cache.find({t[0], t[1], t[2], t[3]}) == cache.end()) {
                        res.push_back(t);
                        cache.insert({t[0], t[1], t[2], t[3]});
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    auto res = fourSum(nums, 0);
    for(auto &vec : res) {
        for(auto &v : vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
