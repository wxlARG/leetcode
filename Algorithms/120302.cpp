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

int func(int A[], int start, int end, int target)
{
	if(start > end)
		return -1;

	int mid = start+(end-start)/2;
	if(target == A[mid])
		return mid;

	if(A[mid] >= A[start])
		if(target < A[mid] && target >= A[start])
			return func(A,start,mid-1,target);
		else
			return func(A,mid+1,end,target);
	else if(A[mid] <= A[end])
		if(target > A[mid] && target <= A[end])
			return func(A,mid+1,end,target);
		else
			return func(A,start,mid-1,target);
}

int search(int A[], int n, int target)
{
	return func(A,0,n-1,target);
}

int main()
{
	int A[] = {1};

	int result = search(A, sizeof(A)/sizeof(A[0]),0);
	cout << result << endl;
	return 0;
}
