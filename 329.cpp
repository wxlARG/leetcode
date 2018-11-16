#include"common.h"
using namespace std;

void helper_solution1(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp, int& res) {
    vector<pair<int, int>> dirs={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int val=1;
    for(auto& dir: dirs) {
        int row=i+dir.first, col=j+dir.second;
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()) continue;
        if(matrix[i][j]<=matrix[row][col]) continue;
        if(dp[row][col]==-1) return;
        val=max(val, dp[row][col]+1);
    }
    dp[i][j]=val;
    res=max(res, val);
    for(auto& dir: dirs) {
        int row=i+dir.first, col=j+dir.second;
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()) continue;
        if(matrix[i][j]<matrix[row][col] && dp[row][col]==-1) helper_solution1(matrix, row, col, dp, res);
    }
}

int longestIncreasingPath_solution1(vector<vector<int>>& matrix) {
    if(matrix.size()==0) return 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    int res=0;
    for(int i=0; i<matrix.size(); ++i) {
        for(int j=0; j<matrix[i].size(); ++j) {
            if(dp[i][j]==-1) helper_solution1(matrix, i, j, dp, res);
        }
    }
    return res;
}

void helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp, int& res) {
    vector<pair<int, int>> dirs={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int val=1;
    for(auto& dir: dirs) {
        int row=i+dir.first, col=j+dir.second;
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()) continue;
        if(matrix[i][j]<=matrix[row][col]) continue;
        if(dp[row][col]==-1) helper(matrix, row, col, dp, res);
        val=max(val, dp[row][col]+1);
    }
    dp[i][j]=val;
    res=max(res, val);
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.size()==0) return 0; 
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    int res=0;
    for(int i=0; i<matrix.size(); ++i) {
        for(int j=0; j<matrix[i].size(); ++j) {
            if(dp[i][j]==-1) helper(matrix, i, j, dp, res);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix={
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    cout << longestIncreasingPath(matrix) << endl;
}
