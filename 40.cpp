#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void helper(vector<int>& candidates, int target, int pos, vector<vector<int>>& res, vector<int>& cache) {
    if(target==0) {
        res.push_back(cache);
        return;
    }
    if(target<0) return;
    for(int i=pos; i<candidates.size(); ++i) {
        if(i>pos && candidates[i]==candidates[i-1]) continue;
        cache.push_back(candidates[i]);
        helper(candidates, target-candidates[i], i+1, res, cache);
        cache.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cache;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, 0, res, cache);
    return res;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    //vector<int> candidates = {1, 1};
    //vector<int> candidates = {2, 2, 2};
    auto res = combinationSum2(candidates, 8);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
