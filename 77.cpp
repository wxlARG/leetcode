#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper_solution1(int start, int end, int n, vector<int>& cache, vector<vector<int>>& res) {
    if(n==0) {
        res.push_back(cache);
        return;
    }
    for(int i=start; i<=end; ++i) {
        cache.push_back(i);
        helper_solution1(i+1, end, n-1, cache, res);
        cache.pop_back();
    }
}

void helper(int start, int end, int n, vector<int>& cache, vector<vector<int>>& res) {
    if(n==0) {
        res.push_back(cache);
        return;
    } else if (start>end) {
        return;
    }
    helper(start+1, end, n, cache, res);
    cache.push_back(start);
    helper(start+1, end, n-1, cache, res);
    cache.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cache;
    helper(1, n, k, cache, res);
    return res;
}

int main() {
    auto res = combine(4, 2);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
