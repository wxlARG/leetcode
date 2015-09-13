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

bool isBadVersion(int version)
{
    return version;
}

int firstBadVersion(int n)
{
    int result=INT_MAX;
    int start=1, end=n;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(isBadVersion(mid))
        {
            if(result>mid)
                result = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return result;
}

int main()
{
    int result = firstBadVersion(10);
    cout << result << endl;
    return 0;
}
