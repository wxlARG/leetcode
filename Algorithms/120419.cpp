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
	int start=0,end=0,pos=0;
	while(end<n)
	{
		start = end;
		while(end<n && A[start]==A[end])
			++end;

		int tmpmin = min(2,end-start);
		for(int i=0; i<tmpmin; ++i)
			A[pos++] = A[start];
	}

	return pos;
}

int main()
{
	int A[] = {1,1,1,2,2,3};

	int result = removeDuplicates(A, sizeof(A)/sizeof(A[0]));
	cout << result << endl;
	for(int i=0; i<result; ++i)
		cout << A[i] << "\t";
	cout << endl;
	return 0;
}
