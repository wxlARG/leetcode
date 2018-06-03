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

void merge(int A[], int m, int B[], int n)
{
	int pos = m+n-1;
	for(int i=m-1; i>=0; --i)
		A[pos--] = A[i];

	int posA=n, posB=0;
	pos=0;
	while(posA<=n+m-1 && posB<=n-1)
	{
		if(A[posA]<B[posB])
			A[pos++] = A[posA++];
		else
			A[pos++] = B[posB++];
	}

	while(posB<=n-1)
		A[pos++] = B[posB++];
}

int main()
{
	int A[10] = {4,5,6};
	int B[] = {2,3,4};

	merge(A,3,B,sizeof(B)/sizeof(B[0]));

	for(int i=0; i<sizeof(A)/sizeof(A[0]); ++i)
		cout << A[i] << endl;
	return 0;
}
