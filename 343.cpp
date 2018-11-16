#include"common.h"
using namespace std;

int integerBreak_solution1(int n) {
    vector<int> dp(n+1, 1);
    for(int i=2; i<=n; ++i) {
        for(int start=1, end=i-start; start<=end; ++start, --end) {
            dp[i]=max(dp[i], max(start, dp[start])*max(end,dp[end]));
        }
    }
    return dp[n];
}

int integerBreak(int n) {
    vector<int> dp(n+1, 1);
    dp[2]=1;
    dp[3]=2;
    dp[4]=4;
    for(int i=5; i<=n; ++i) {
        dp[i]=3*max(i-3, dp[i-3]);
    }
    return dp[n];
}

int main() {
    cout << integerBreak(2) << endl;
    cout << integerBreak(10) << endl;
}
