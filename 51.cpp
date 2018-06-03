#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool check(vector<string>& cache, int x, int y) {
    for(int i=0; i<x; ++i) {
        if(cache[i][y]=='Q') return false;
        if(y-(x-i)>=0 && cache[i][y-(x-i)]=='Q') return false;
        if(y+(x-i)<cache.size() && cache[i][y+(x-i)]=='Q') return false;
    }
    return true;
}

void helper(int i, vector<vector<string>>& res, vector<string>& cache) {
    if(i==cache.size()) {
        res.push_back(cache);
        return;
    }

    for(int j=0; j<cache.size(); ++j) {
        if(check(cache, i, j)) {
            cache[i][j] = 'Q';
            helper(i+1, res, cache);
            cache[i][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> cache(n, string(n, '.'));
    helper(0, res, cache);
    return res;
}

int main() {
    auto res = solveNQueens(6);
    for(auto &vec: res) {
        for(auto &str: vec) {
            cout << str << endl;
        }
        cout << endl;
    }
}
