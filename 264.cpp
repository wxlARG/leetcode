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

int nthUglyNumber(int n)
{
    vector<int> cache(1,1);
    int a=0,b=0,c=0;

    while(cache.size()<n)
    {
        int tmp1=INT_MAX;
        int tmp2=INT_MAX; 
        int tmp3=INT_MAX;
        if(a!=-1)
            tmp1 = cache[a]*2;
        if(b!=-1)
            tmp2 = cache[b]*3;
        if(c!=-1)
            tmp3 = cache[c]*5;

        int result = min(min(tmp1,tmp2),tmp3);
        if(result > cache.back())
            cache.push_back(result);

        if(result==tmp1)
            ++a;
        else if(result==tmp2)
            ++b;
        else
            ++c;
    }

    return cache.back();
}

int main()
{
    int result = nthUglyNumber(10);
    cout << result << endl;
    return 0;
}
