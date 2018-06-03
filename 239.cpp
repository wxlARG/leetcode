#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

void func(list<pair<int,int> >& cache, int num)
{
    if(cache.empty() || num<cache.back().first)
        cache.push_back(make_pair(num,1));
    else
    {
        while(!cache.empty() && num>cache.back().first)
            cache.pop_back();
        if(!cache.empty() && num==cache.back().first)
            ++cache.back().second;
        else
            cache.push_back(make_pair(num,1));
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    list<pair<int,int> > cache;

    for(int i=0; i<k; ++i)
        func(cache,nums[i]);

    if(!cache.empty())
        result.push_back(cache.front().first);

    for(int i=k; i<nums.size(); ++i)
    {
        if(nums[i-k] == cache.front().first)
            --cache.front().second;
        if(cache.front().second == 0)
            cache.pop_front();
        func(cache,nums[i]);
        result.push_back(cache.front().first);
    }
    return result;
}

int main()
{
    int arr[] = {1,-1};
    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
        nums.push_back(arr[i]);

    vector<int> result = maxSlidingWindow(nums,1);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
