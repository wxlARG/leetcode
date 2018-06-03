#include<iostream>
#include<sstream>
#include<vector>
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

int lengthOfLIS(vector<int>& nums)
{
    map<int,int> cache;
    vector<int> lens;

    for(int i=0; i<nums.size(); ++i)
    {
        multimap<int,int>::iterator it = cache.lower_bound(nums[i]);
        if(it==cache.end())
        {
            lens.push_back(nums[i]);
            cache.insert(make_pair(nums[i],lens.size()-1));
        }
        else
        {
            int pos = it->second;
            if(nums[i] != lens[pos])
            {
                lens[pos] = nums[i];
                cache.erase(it);
                cache.insert(make_pair(nums[i],pos));
            }
        }
    }
    return lens.size();
}

int main()
{
    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums;

    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

    int result = lengthOfLIS(nums);
    cout << result << endl;
	return 0;
}
