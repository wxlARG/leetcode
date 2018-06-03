#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int res=INT_MAX;
    vector<int> dp(triangle.size(), 0);
    dp[0]= triangle[0][0];
    for(int i=1; i<triangle.size(); ++i) {
        for(int j=i; j>=0; --j) {
            dp[j]=min(j>0? dp[j-1]: INT_MAX, j<i? dp[j]: INT_MAX)+triangle[i][j];
        }
    }
    for(auto &v: dp) res=min(res, v);
    return res;
}

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle) << endl;
}
