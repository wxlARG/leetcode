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

int maxProduct(int A[], int n)
{
	int result = A[0];
	int max = A[0];
	int min = A[0];

	for(int i=1; i<n; ++i)
	{
		int tmp1 = max*A[i];
		int tmp2 = min*A[i];

		if(tmp1 < tmp2)
		{
			min = tmp1;
			max = tmp2;
		}
		else
		{
			min = tmp2;
			max = tmp1;
		}

		if(max < A[i])
			max = A[i];

		if(min > A[i])
			min = A[i];

		if(result < max)
			result = max;
	}

	return result;
}

int main()
{
	int arr[] = {2,3,-2,4};

	int result = maxProduct(arr, sizeof(arr)/sizeof(arr[0]));
	cout << result << endl;
	return 0;
}
