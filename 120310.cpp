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

int trap(int A[], int n)
{
	if(n == 0)
		return 0;

	int result = 0;
	int max = A[0];
	int pos = 0;

	for(int i=0; i<n; ++i)
	{
		if(A[i]>max)
		{
			max = A[i];
			pos = i;
		}
	}

	int start = 0;
	for(int i=1; i<=pos; ++i)
	{
		if(A[i]<A[start])
			result += A[start]-A[i];
		else
			start = i;
	}

	start = n-1;
	for(int i=n-2; i>=pos; --i)
	{
		if(A[i]<A[start])
			result += A[start]-A[i];
		else
			start = i;
	}
	return result;
}

int main()
{
	int arr[] = {4,2,0,3,2,5};

	int result = trap(arr, sizeof(arr)/sizeof(arr[0]));
	cout << result << endl;
	return 0;
}
