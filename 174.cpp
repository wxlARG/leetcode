#include"common.h"
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    vector<int> dp(dungeon[0].size(), 0);
    int maxi=dungeon.size()-1, maxj=dungeon[0].size()-1;
    dp.back() = max(1, 1-dungeon[maxi][maxj]);
    for(int i=maxi; i>=0; --i) {
        for(int j=maxj; j>=0; --j) {
            if(i==maxi && j==maxj) continue;
            int r = (j==maxj? INT_MAX: dp[j+1]);
            int d = (i==maxi? INT_MAX: dp[j]);
            dp[j]=max(min(r, d)-dungeon[i][j], 1);
        }
    }
    return dp[0];
}

int main() {
    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << calculateMinimumHP(dungeon) << endl;
}
