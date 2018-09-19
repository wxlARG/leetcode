#include"common.h"
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    pair<int, int> dp={0, 0};
    int diff=-prices[0];
    for(int i=1; i<prices.size(); ++i) {
        int val=max(dp.second, prices[i]+diff);
        diff=max(diff, dp.first-prices[i]);
        dp.first=dp.second;
        dp.second=val;
    }
    return dp.second;
}

int main() {
    vector<int> prices={1,2,3,0,2};
    cout << maxProfit(prices) << endl;
}
