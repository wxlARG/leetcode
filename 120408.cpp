#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

void sortColors(int A[], int n)
{
	int pos1 = 0;
	int pos2 = n-1;
	int start = 0;

	while(start<=pos2)
	{
		if(A[pos2]==2)
		{
			--pos2;
			continue;
		}

		if(A[start]==0)
			swap(A[start++],A[pos1++]);
		else if(A[start]==2)
			swap(A[start],A[pos2--]);
		else
			++start;
	}
}

int main()
{
	int A[] = {2,1,2,0,1,2};
	sortColors(A,sizeof(A)/sizeof(A[0]));
	for(int i=0; i<sizeof(A)/sizeof(A[0]); ++i)
		cout << A[i] << endl;
	return 0;
}
