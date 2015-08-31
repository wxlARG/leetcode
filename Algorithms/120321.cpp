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

/*int maxSubArray(int A[], int n)
{
	int sum = 0;
	int result = INT_MIN;

	for(int pos=0; pos<n; ++pos)
	{
		sum += A[pos];
		if(result < sum)
			result = sum;
		if(sum < 0)
			sum = 0;
	}
	return result;
}*/

void func(int A[], int start, int end, int& max, int& startval, int& endval, int& whole)
{
	if(start == end)
	{
		startval = endval = whole = A[start];
		if(max < A[start])
			max = A[start];
		return;
	}

	int start1, end1;
	int start2, end2;
	int whole1, whole2;

	int mid = start+(end-start)/2;
	func(A,start,mid,max,start1,end1,whole1);
	func(A,mid+1,end,max,start2,end2,whole2);

	whole = whole1+whole2;

	if(start1 < whole1+start2)
		startval = whole1+start2;
	else
		startval = start1;

	if(end2 < whole2+end1)
		endval = whole2+end1;
	else
		endval = end2;

	if(max<startval)
		max = startval;

	if(max < endval)
		max = endval;

	if(max< whole)
		max = whole;

	if(max<end1+start2)
		max = end1+start2;
}

int maxSubArray(int A[], int n)
{
	int startval;
	int endval;
	int whole;
	int max = INT_MIN;

	func(A,0,n-1,max,startval,endval,whole);
	return max;
}

int main()
{
	int A[] = {0,-3,2,1,-2,3};
//	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	int result = maxSubArray(A,sizeof(A)/sizeof(A[0]));
	cout << result << endl;
	return 0;
}
