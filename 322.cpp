#include"common.h"
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if(amount==0) return 0;
    if(coins.empty()) return -1;
    vector<int> dp(amount+1, INT_MAX);
    dp[0]=0;
    for(int i=1; i<=amount; ++i) {
        int m=INT_MAX;
        for(auto& coin: coins) {
            if(i-coin>=0 && dp[i-coin]!=INT_MAX) m=min(m, dp[i-coin]+1);
        }
        dp[i]=m;
    }
    return dp.back()==INT_MAX? -1: dp.back();
}

int main() {
    vector<int> coins={1, 2, 5};
    cout << coinChange(coins, 11) << endl;
}
