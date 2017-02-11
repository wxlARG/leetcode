#include<iostream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if(prices.size() <= 1)
        return 0;

    pair<int, int> cache(0,0);
    int maxval= -prices[0];

    for(int i=1; i<prices.size(); ++i)
    {
        int tmp = cache.first;
        cache.first = cache.second;
        cache.second = max(prices[i]+maxval,cache.first);
        maxval = max(maxval,tmp-prices[i]);
    }
    return cache.second;
}

int main()
{
    int a[] = {1, 4, 2};
    vector<int> prices;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        prices.push_back(a[i]);

    int result = maxProfit(prices);
    cout << result << endl;
    return 0;
}
