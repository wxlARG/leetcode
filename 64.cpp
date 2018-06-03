#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size()==0 || grid[0].size()==0) return 0;
    vector<int> cache(grid[0].size(), 0);
    cache[0] = grid[0][0];
    for(int i=0; i<grid.size(); ++i) {
        for(int j=0; j<grid[0].size(); ++j) {
            if(i==0 && j==0) continue;
            int left = (i>0? cache[j]: INT_MAX);
            int up = (j>0? cache[j-1]: INT_MAX);
            cache[j] = min(left, up) + grid[i][j];
        }
    }
    return cache.back();
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << minPathSum(grid) << endl;
}
