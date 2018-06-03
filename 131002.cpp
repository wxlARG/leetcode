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

int singleNumber(int A[], int n)
{
	int result = 0;
	vector<int> cache(32,0);
	for(int i=0; i<n; ++i)
	{
		int tmp = A[i];
		for(int j=0; j<32; ++j)
		{
			cache[j] += tmp & 1;
			tmp>>=1;
		}
	}

	for(int i=0; i<32; ++i)
	{
		cache[i] %= 3;
		if(cache[i])
			cache[i] = 1;

		result |= cache[i]<<i;
	}

	return result;
}

int main()
{
	int A[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	int result = singleNumber(A, sizeof(A)/sizeof(A[0]));
	cout << result << endl;
	return 0;
}
