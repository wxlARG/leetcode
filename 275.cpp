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

int hIndex(vector<int>& citations)
{
    int result = 0;
    int start=0, end=citations.size()-1;

    while(start<=end)
    {
        int pos = start+(end-start)/2;
        if(citations[pos] >= citations.size()-pos)
        {
            result = citations.size()-pos;
            end = pos-1;
        }
        else
            start = pos+1;
    }
    return result;
}

int main()
{
    int a[] = {0,1,3,5,6};
    vector<int> citations;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        citations.push_back(a[i]);

    int result = hIndex(citations);
    cout << result << endl;
    return 0;
}
