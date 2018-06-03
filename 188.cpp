#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

int greedy(vector<int>& prices) {
    int res=0;
    for(int i=1; i<prices.size(); ++i) {
        if(prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
    }
    return res;
}

int maxProfit(int k, vector<int>& prices) {
    if(prices.size()<=1) return 0;
    if(k>=prices.size()/2) return greedy(prices);
    vector<int> dp(prices.size(), 0);
    for(int j=0; j<k; ++j) {
        int mc=dp[0]-prices[0];
        for(int i=1; i<prices.size(); ++i) {
            int tmp=dp[i];
            dp[i]=max(prices[i]+mc, dp[i-1]);
            mc=max(mc, tmp-prices[i]);
        }
    }
    return dp.back();
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    cout << maxProfit(2, prices) << endl;
}
