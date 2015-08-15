#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

bool canJump(int A[], int n)
{
	int max = 0;

	for(int i=0; i<n; ++i)
	{
		int step = A[i];
		if(max < i+step)
			max = i+step;

		if(max >= n-1)
			return true;

		if(max == i)
			return false;
	}

	return true;
}

int main()
{
	int arr[] = {0};
	bool result = canJump(arr, sizeof(arr)/sizeof(arr[0]));
	cout << result << endl;

	return 0;
}
