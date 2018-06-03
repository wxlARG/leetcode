#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int maxProfit(vector<int>& prices) {
    int res=0;
    for(int i=1; i<prices.size(); ++i) {
        int v=prices[i]-prices[i-1];
        res += v>0? v: 0; 
    }
    return res;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}
