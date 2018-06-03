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

int helper(int i, vector<string>& cache) {
    if(i==cache.size()) {
        return 1;
    }

    int res = 0;
    for(int j=0; j<cache.size(); ++j) {
        if(check(cache, i, j)) {
            cache[i][j] = 'Q';
            res += helper(i+1, cache);
            cache[i][j] = '.';
        }
    }
    return res;
}

int totalNQueens(int n) {
    vector<string> cache(n, string(n, '.'));
    return helper(0, cache);
}

int main() {
    cout << totalNQueens(4) << endl;
}
