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

/*
int minSubArrayLen(int s, vector<int>& nums)
{
	 int result = 0;
	 int cache = 0;
	 int start = 0, end=0;

	 for(;end<nums.size();++end)
	 {
		 cache += nums[end];
		 if(cache >= s)
		 {
			 int len = end-start+1;
			 if(result == 0 || len < result)
				 result = len;

			 while(start<=end)
			 {
				 cache -= nums[start];
				 ++start;
				 if(cache < s)
					 break;
				 len = end-start+1;
				 if(len<result)
					 result = len;
			 }
		 }
	 }
	 return result;
}
*/

int func(int s, vector<int>& nums, int start, int end)
{
	if(start > end)
		return 0;

	int mid = start+(end-start)/2;
	int result = func(s,nums,start,mid-1);
	int right = func(s,nums,mid+1,end);
	if(result == 0) result = right;
	else result = right == 0 ? result : min(right,result);

	int midsize = 1;
	int cache = nums[mid];
	int leftpos=0, rightpos=0;

	while(cache < s)
	{
		++leftpos,++rightpos;
		int leftval=0, rightval=0;
		if(mid-leftpos >= 0)
			leftval = nums[mid-leftpos];
		if(mid+rightpos<nums.size())
			rightval = nums[mid+rightpos];

		if(leftval==0 && rightval==0)
			break;

		if(cache+leftval >= s)
		{
			cache+=leftval;
			++midsize;
			break;
		}
		else if(cache+rightval>=s)
		{
			cache+=rightval;
			++midsize;
			break;
		}

		cache += leftval + rightval;
		midsize += 2;

		if(cache >= s)
			break;
	}

	if(midsize==0 || cache<s)
		return result;
	else
		return result==0 ? midsize : min(result,midsize);
}

int minSubArrayLen(int s, vector<int>& nums)
{
	return func(s,nums,0,nums.size()-1);
}

int main()
{
	int arr[] = {5,1,3,5,10,7,4,9,2,8};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);


	int result = minSubArrayLen(15,nums);
	cout << result << endl;
	return 0;
}
