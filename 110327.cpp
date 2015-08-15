#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;

int func(int A[],int m,int B[],int n,int k)
{
	if(m>n)
		return func(B,n,A,m,k);

	if(m==0)
		return B[k-1];

	if(k==1)
		return min(A[0],B[0]);

	int pa = (m+1)/2;
	int pb = (n+1)/2;

	int aNum = pa-1;
	int bNum = pb-1;

	if(aNum+bNum+1 < k)
	{
		if(A[pa-1] < B[pb-1])
			return func(A+pa,m-aNum-1,B,n,k-1-aNum);
		else 
			return func(A,m,B+pb,n-bNum-1,k-1-bNum);
	}
	else
	{
		if(A[pa-1] < B[pb-1])
			return func(A,m,B,bNum,k);
		else
			return func(A,aNum,B,n,k);
	}
}

/*
int func(int A[],int m,int B[],int n,int k)
{
	if(m>n)
		return func(B,n,A,m,k);

	if(m==0)
		return B[k-1];

	if(k==1)
		return min(A[0],B[0]);

	int pa = min(k/2,m);
	int pb = k-pa;

	if(A[pa] > B[pb])
		return func(A,m,B+pb,n-pb,k-pb);
	else if(A[pa] < B[pb])
		return func(A+pa,m-pa,B,n,k-pa);
	else 
		return A[pa];
}
*/

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	if((m+n)%2 == 0)
		return (func(A,m,B,n,(m+n)/2) + func(A,m,B,n,(m+n)/2+1))/2.0;
	else
		return func(A,m,B,n,(m+n)/2+1);
}

int main()
{
	int A[] = {1,3,5,7,9};
	int B[] = {2,4,6,8};
//	int A[] = {1,2};
//	int B[] = {3,4,5};
	double middle = findMedianSortedArrays(A,sizeof(A)/sizeof(A[0]),B,sizeof(B)/sizeof(B[0]));
	cout << middle <<endl;
	return 0;
}


