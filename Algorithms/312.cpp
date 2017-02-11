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

int maxCoins(vector<int>& nums)
{
    int n=nums.size();
    if(n==0)
        return 0;

    vector<vector<int>> cache(n, vector<int>(n, 0));

    for(int l=0; l<n; ++l)
        for(int s=0; s<n-l; ++s)
        {
            int e = s+l;
            int maxval = 0;
            int left = s-1<0 ? 1 : nums[s-1];
            int right = e+1>=n ? 1 : nums[e+1];
            for(int k=s; k<=e; ++k)
            {
                int tmp = left*nums[k]*right;
                if(k-1>=s)
                    tmp += cache[s][k-1];
                if(k+1<=e)
                    tmp += cache[k+1][e];

                maxval = max(maxval, tmp);
            }
            cache[s][e] = maxval;
        }
    return cache[0][n-1];
}

int main()
{
    vector<int> nums {3, 1, 5, 8};
    int result = maxCoins(nums);
    cout << result << endl;
    return 0;
}
