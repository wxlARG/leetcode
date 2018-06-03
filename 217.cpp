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
#include<time.h>
#include<set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	set<int> cache;
	for(int i=0; i<nums.size(); ++i)
		cache.insert(nums[i]);

	return !(cache.size()==nums.size());
}

int main()
{
	int arr[] = {1,7,6,5,4,3,2,1};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	bool result = containsDuplicate(nums);
	cout << result << endl;
	return 0;
}
