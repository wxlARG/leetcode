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

bool func(vector<int>& nums, int k)
{
	unordered_map<int, int> cache;
	for(int i=0; i<nums.size(); ++i)
	{
		unordered_map<int, int>::iterator it = cache.find(nums[i]);
		if(it == cache.end())
			cache.insert(make_pair(nums[i],i));
		else
		{
			if(i-it->second<=k)
				return true;
			it->second = i;
		}
	}

	return false;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	if(t==0)
		return func(nums,k);
	if(t<0)
		return false;

	unordered_map<int, int> cache;
	for(int i=0; i<nums.size(); ++i)
	{
		int tmp = floor(1.0*nums[i]/t);
		if(i>k)
			cache.erase(floor(1.0*nums[i-k-1]/t));

		if(cache.find(tmp) != cache.end())
			return 1;

		unordered_map<int, int>::iterator it1 = cache.find(tmp-1);
		unordered_map<int, int>::iterator it2 = cache.find(tmp+1);

		if(it1 != cache.end() && nums[i]-it1->second <= t)
			return 1;
		else if(it2 != cache.end() && it2->second-nums[i] <= t)
			return 1;
		else
			cache.insert(make_pair(tmp,nums[i]));
	}

	return 0;
}

int main()
{
	int arr[] = {1,7,6,5,1,4,3,2};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	bool result = containsNearbyAlmostDuplicate(nums,3,1);

	cout << result << endl;
	return 0;
}
