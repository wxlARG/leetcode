#include"common.h"
using namespace std;

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    for(int k=0; k<n; ++k) {
        for(int start=1; start<=n-k; ++start) {
            int end=start+k;
            if(start==end) {
                dp[start][end]=0;
            } else {
                for(int j=start; j<=end; ++j) {
                    int left = (j==start? 0: dp[start][j-1]);
                    int right = (j==end? 0: dp[j+1][end]);
                    dp[start][end]=min(dp[start][end], max(left,right)+j);
                }
            }
        }
    }
    return dp[1][n];
}

int main() {
    cout << getMoneyAmount(10) << endl;
}
