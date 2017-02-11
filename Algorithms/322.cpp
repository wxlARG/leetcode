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
#include<unordered_set>
#include<unordered_map>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> cache(amount+1, -1);
    cache[0] = 0;
    for(int i=0; i<=amount; ++i)
    {
        for(auto coin:coins)
        {
            if(i<coin) continue;
            else
            {
                int val = cache[i-coin];
                if(val == -1) continue;
                if(cache[i] == -1 || val+1 < cache[i])
                    cache[i] = val+1;
            }
        }
    }
    return cache.back();
}

int main()
{
    vector<int> coins {19,28,176,112,30,260,491,128,70,137,253};
    int result = coinChange(coins, 8359);

//    vector<int> coins {1,2,5};
//    int result = coinChange(coins, 11);
    cout << result << endl;
    return 0;
}
