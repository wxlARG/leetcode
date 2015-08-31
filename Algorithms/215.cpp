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
using namespace std;

int func(vector<int>& nums, int start, int end, int k)
{
	if(start == end)
		return nums[start];

	int tmp = start + rand()%(end-start+1);
	swap(nums[tmp],nums[end]);

	int pos=start;
	for(int i=start; i<end; ++i)
		if(nums[i]>nums[end])
			swap(nums[i],nums[pos++]);

	swap(nums[pos],nums[end]);

	if(pos+1 == k)
		return nums[pos];
	else if(pos+1 < k)
		return func(nums,pos+1,end,k);
	else 
		return func(nums,start,pos-1,k);
}

int findKthLargest(vector<int>& nums, int k)
{
	srand((unsigned)time(NULL));
	return func(nums,0,nums.size()-1,k);
}

int main()
{
	int arr[] = {7,6,5,4,3,2,1};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	int result = findKthLargest(nums,5);
	cout << result << endl;
	return 0;
}
