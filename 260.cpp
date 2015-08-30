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

vector<int> singleNumber(vector<int>& nums)
{
    vector<int> result;
    int cache = 0;
    int pos = 0;
    
    for(int i=0; i<nums.size(); ++i)
        cache ^= nums[i];

    while((cache & 1) ==0)
    {
        cache >>=1;
        ++pos;
    }

    int start = 0;
    for(int i=0; i<nums.size(); ++i)
        if(((nums[i]>>pos) & 1) != 0)
            swap(nums[i],nums[start++]);

    cache = 0;
    for(int i=0; i<start; ++i)
        cache ^= nums[i];
    result.push_back(cache);

    cache=0;
    for(int i=start; i<nums.size(); ++i)
        cache ^= nums[i];
    result.push_back(cache);
    return result;
}

int main()
{
    int a[] = {1, 2, 1, 3, 2, 5};
    vector<int> nums;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

	vector<int> result = singleNumber(nums);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;
	return 0;
}
