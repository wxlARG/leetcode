#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int maxProfit(vector<int>& prices) {
    int res=0, min_price=INT_MAX;
    for(auto &v: prices) {
        min_price=min(min_price, v);
        res = max(res, v-min_price);
    }
    return res;
}

int main() {
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
}
