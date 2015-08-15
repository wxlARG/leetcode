#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int firstMissingPositive(int A[], int n)
{
	for(int i=0; i<n; ++i)
	{
		int pos = A[i]-1;
		if(pos>=0 && pos<n && pos!=i && A[pos]!=A[i])
		{
			swap(A[pos],A[i]);
			--i;
		}
	}

	for(int i=0; i<n; ++i)
		if(A[i]-1 != i)
			return i+1;

	return n+1;
}

int main()
{
	int arr[] = {3,4,-1,1};

	int result = firstMissingPositive(arr, sizeof(arr)/sizeof(arr[0]));
	cout << result << endl;
	return 0;
}
