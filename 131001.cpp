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
	for(int i=0; i<n; ++i)
		result ^= A[i];
	return result;
}

int main()
{
	int A[] = {1,2,3,4,5,1,2,3,4};
	int result = singleNumber(A, sizeof(A)/sizeof(A[0]));
	cout << result << endl;
	return 0;
}
