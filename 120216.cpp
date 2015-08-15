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

int removeElement(int A[], int n, int elem)
{
	int pos = 0;
	for(int i=0; i<n; ++i)
		if(A[i] != elem)
			swap(A[i],A[pos++]);
	return pos;
}

int main()
{
	int A[] = {2,2,3};
	int result = removeElement(A,sizeof(A)/sizeof(A[0]),3);
	cout << result << endl;
	for(int i=0; i<result; ++i)
		cout << A[i] << endl;
	return 0;
}
