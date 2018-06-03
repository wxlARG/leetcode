#include"common.h"
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    grid[i][j]='2';
    vector<pair<int, int>> pos = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for(auto &d: pos) {
        int newx=i+d.first, newy=j+d.second;
        if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]=='1') dfs(grid, newx, newy);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int res=0;
    for(int i=0; i<grid.size(); ++i) {
        for(int j=0; j<grid[i].size(); ++j) {
            if(grid[i][j]=='1') {
                dfs(grid, i, j);
                ++res;
            }
        }
    }
    return res;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << numIslands(grid) << endl;
}
