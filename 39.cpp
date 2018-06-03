#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void helper(vector<int>& candidates, int target, int pos, vector<vector<int>>& res, vector<int>& cache) {
    if(target == 0) {
        res.push_back(cache);
        return;
    }
    if(target<0) return;
    for(int i=pos; i<candidates.size(); ++i) {
        cache.push_back(candidates[i]);
        helper(candidates, target-candidates[i], i, res, cache);
        cache.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cache;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, 0, res, cache);
    return res;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    auto res = combinationSum(candidates, 7);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
