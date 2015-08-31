#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int jump(int A[], int n)
{
	int max = 0;
	int lastmax = max;
	vector<int> step(n,-1);
	step[0] = 0;

	for(int i=0; i<n; ++i)
	{
		int val = A[i];
		if(max < i+val)
		{
			lastmax = max;
			max = i+val;
			for(int j=lastmax+1; j<n && j<=max; ++j)
				step[j] = step[i]+1;
		}

		if(step[n-1] != -1)
			return step[n-1];
	}

	return step[n-1];
}

int main()
{
	int arr[] = {2,3,1,1,4};
	int result = jump(arr, sizeof(arr)/sizeof(arr[0]));
	cout << result << endl;

	return 0;
}
