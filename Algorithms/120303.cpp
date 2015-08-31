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

int searchInsert(int A[], int n, int target)
{
	int start = 0;
	int end = n-1;

	while(start<=end)
	{
		int mid = start+(end-start)/2;

		if(A[mid]<target)
			start = mid+1;
		else if(A[mid]>target)
			end = mid-1;
		else
			return mid;
	}
	return start;
}

int main()
{
	int A[] = {1,3,5,6};

	int result = searchInsert(A, sizeof(A)/sizeof(A[0]),0);
	cout << result << endl;
	return 0;
}
