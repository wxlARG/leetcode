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

vector<int> func(int A[], int start, int end, int target)
{
	if(start > end)
	{
		vector<int> tmp;
		tmp.push_back(-1);
		tmp.push_back(-1);
		return tmp;
	}

	if(A[start] == A[end])
	{
		vector<int> tmp;
		if(A[start] == target)
		{
			tmp.push_back(start);
			tmp.push_back(end);
			return tmp;
		}
		else
		{
			tmp.push_back(-1);
			tmp.push_back(-1);
			return tmp;
		}
	}

	int mid = start+(end-start)/2;

	if(A[mid]<target)
		return func(A,mid+1,end,target);
	else if(A[mid]>target)
		return func(A,start,mid-1,target);
	else
	{
		vector<int> tmp;
		vector<int> left = func(A,start,mid-1,target);
		vector<int> right = func(A,mid+1,end,target);

		if(left[0] == -1)
			tmp.push_back(mid);
		else
			tmp.push_back(min(left[0],mid));

		tmp.push_back(max(right[1],mid));
		return tmp;
	}
}

vector<int> searchRange(int A[], int n, int target)
{
	return func(A,0,n-1,target);
}

int main()
{
	int A[] = {5, 7, 7, 8, 8, 10};

	vector<int> result = searchRange(A, sizeof(A)/sizeof(A[0]),8);
	cout << result[0] << "\t" << result[1] << endl;
	return 0;
}
