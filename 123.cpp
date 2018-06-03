#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0;
    vector<int> dp(prices.size(), 0);
    for(int k=0; k<2; ++k) {
        int m=INT_MIN, cache=dp[0];
        for(int i=1; i<prices.size(); ++i) {
            int tmp=dp[i];
            m=max(m, cache-prices[i-1]);
            int v=prices[i]+m;
            dp[i] = max(dp[i-1], v);
            cache=tmp;
        }
    }
    return dp.back();
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}
