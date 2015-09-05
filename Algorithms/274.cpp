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

int func(vector<int>& a, int start, int end)
{
    int result = 0;
    if(start>end)
        return result;

    int pos = start + rand()%(end-start+1);
    swap(a[pos],a[end]);
    
    pos = start;
    for(int i=start; i<end; ++i)
        if(a[i] < a[end])
            swap(a[i],a[pos++]);
    swap(a[end],a[pos]);

    if(a[pos] >= a.size()-pos)
    {
        result = a.size()-pos;
        int tmp = func(a,start,pos-1);
        result = max(result,tmp);
        return result;
    }
    return func(a,pos+1,end);
}

int hIndex(vector<int>& citations)
{
    srand((unsigned)time(NULL));
    return func(citations,0,citations.size()-1);
}

/*
//------nlgn
int hIndex(vector<int>& citations)
{
    int result = 0;
    sort(citations.begin(),citations.end());
    for(int i=citations.size()-1; i>=0; --i)
        if(citations[i] >= citations.size()-i)
            result = citations.size()-i;
    return result;
}
*/

int main()
{
//    int a[] = {3, 0, 6, 1, 5};
    int a[] = {0,0,0};
    vector<int> citations;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        citations.push_back(a[i]);

    int result = hIndex(citations);
    cout << result << endl;
    return 0;
}
