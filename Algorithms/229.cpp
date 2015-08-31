#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
	vector<int> result;
	unordered_map<int, int> cache;

	for(int i=0; i<nums.size(); ++i)
	{
		++cache[nums[i]];

		if(cache.size() == 3)
		{
			vector<int> tmp;

			for(unordered_map<int, int>::iterator it=cache.begin(); it!=cache.end(); ++it)
				if(--it->second == 0)
					tmp.push_back(it->first);

			for(int j=0; j<tmp.size(); ++j)
				cache.erase(tmp[j]);
		}
	}

	for(unordered_map<int, int>::iterator it=cache.begin(); it!=cache.end(); ++it)
	{
		int tmp = it->first;
		int count = 0;
		for(int i=0; i<nums.size(); ++i)
			if(nums[i] == tmp)
				++count;

		if(count > nums.size()/3)
			result.push_back(tmp);
	}

	return result;
}

int main()
{
	int arr[] = {1,2,0,4,5,0,6,7,8,9,9,9,9,9,9,0,0,0,0,0};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	vector<int> result = majorityElement(nums);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
