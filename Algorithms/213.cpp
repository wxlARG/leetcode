#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int rob(vector<int>& nums)
{
	if(nums.size() == 0)
		return 0;
	else if(nums.size() == 1)
		return nums[0];
	else if(nums.size() == 2)
		return max(nums[0],nums[1]);

	int result;
	vector<int> cache(nums.size(),0);

	cache[0] = nums[0];
	cache[1] = max(nums[1],nums[0]);

	for(int i=2; i<nums.size()-1; ++i)
		cache[i] = max(cache[i-1],cache[i-2]+nums[i]);
	result = cache[nums.size()-2];

	cache[1] = nums[1];
	cache[2] = max(nums[1],nums[2]);
	for(int i=3;i<nums.size(); ++i)
		cache[i] = max(cache[i-1],cache[i-2]+nums[i]);
	result = max(result, cache[nums.size()-1]);

	return result;
}

int main()
{
	int arr[] = {2,1,1,2};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	int result = rob(nums);
	cout << result << endl;
	return 0;
}
