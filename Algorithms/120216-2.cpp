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

int removeDuplicates(int A[], int n)
{
	if(n==0) return 0;
	
	int pos = 1;
	for(int i=1; i<n; ++i)
		if(A[i] != A[i-1])
			A[pos++] = A[i];

	return pos;
}

int main()
{
	int A[] = {1,1,2};
	int result = removeDuplicates(A,sizeof(A)/sizeof(A[0]));
	cout << result << endl;
	for(int i=0; i<result; ++i)
		cout << A[i] << endl;
	return 0;
}
