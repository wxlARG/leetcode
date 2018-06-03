#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0) return 0;
    vector<int> cache(obstacleGrid[0].size(), 0);
    if(obstacleGrid[0][0]!=1) cache[0] = 1;
    for(int i=0; i<obstacleGrid.size(); ++i) {
        for(int j=0; j<obstacleGrid[0].size(); ++j) {
            if(i==0 && j==0) continue;
            if(obstacleGrid[i][j]) {
                cache[j] = 0;
                continue;
            }
            cache[j] = (i>0? cache[j]: 0) + (j>0? cache[j-1]: 0);
        }
    }
    return cache.back();
}

int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}
