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
#include<unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
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

int main()
{
	int arr[] = {1,7,6,5,4,3,2,1};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	bool result = containsNearbyDuplicate(nums,3);
	cout << result << endl;
	return 0;
}
