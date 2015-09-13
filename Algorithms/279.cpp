#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

int numSquares(int n)
{
    vector<int> cache(n,1);

    for(int i=1; i<cache.size(); ++i)
    {
        int tmp = i+1;
        int max = tmp;
        int k=sqrt(tmp);
        for(int j=k; j>=1; --j)
            max = min(max,cache[tmp-j*j-1]+1);
        cache[i] = max;
    }

    return cache.back();
}

int main()
{
    int result = numSquares(28);
    cout << result << endl;
    return 0;
}
