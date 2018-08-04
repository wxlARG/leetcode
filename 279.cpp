#include"common.h"
using namespace std;

int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    for(int i=1; i<=n; ++i) {
        for(int k=1; k*k<=i; ++k) {
            dp[i]=min(dp[i], k*k==i? 1: 1+dp[i-k*k]);
        }
    }
    return dp.back();
}

int main() {
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;
}
