#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

int uniquePaths_solution1(int m, int n) {
    vector<vector<int>> cache(m, vector<int>(n, 0));
    cache[0][0] = 1;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(i==0 && j==0) continue;
            cache[i][j] = (i>0? cache[i-1][j]: 0) + (j>0? cache[i][j-1]: 0);
        }
    }
    return cache[m-1][n-1];
}

int uniquePaths(int m, int n) {
    vector<int> cache(n, 0);
    cache[0] = 1;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(i==0 && j==0) continue;
            cache[j] = (i>0? cache[j]: 0) + (j>0? cache[j-1]: 0);
        }
    }
    return cache.back();
}

int main() {
    cout << uniquePaths(3, 7) << endl;
}
