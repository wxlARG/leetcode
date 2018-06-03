#include"common.h"
using namespace std;

void helper(vector<vector<int>>& res, vector<int>& cache, int k, int n, int start, int sum) {
    if(cache.size()==k) {
        if(sum==n) res.push_back(cache);
        return;
    } else if(sum>=n) {
        return;
    }
    for(int i=start; i<=9; ++i) {
        sum+=i;
        cache.push_back(i);
        helper(res, cache, k, n, i+1, sum);
        cache.pop_back();
        sum-=i;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cache;
    helper(res, cache, k, n, 1, 0);
    return res;
}

int main() {
    auto res=combinationSum3(3, 9);
    for(auto &v: res) {
        for(auto &n: v) cout << n << "\t";
        cout << endl;
    }
}
