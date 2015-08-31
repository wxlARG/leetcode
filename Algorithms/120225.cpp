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

void nextPermutation(vector<int> &num)
{
	int size = num.size();
	if(size == 1)
		return;

	int i=0;
	for(i=size-1; i>0; --i)
		if(num[i] > num[i-1])
			break;

	if(i==0)
	{
		int start = i;
		int end = size-1;

		while(start < end)
		{
			swap(num[start],num[end]);
			++start;
			--end;
		}

		return;
	}

	int val = num[i-1];
	int max = num[i];
	int pos = i;

	for(int j=i; j<size && num[j]>val; ++j)
		if(num[j]<=max)
		{
			max = num[j];
			pos = j;
		}

	swap(num[i-1],num[pos]);
	int start = i;
	int end = size-1;

	while(start < end)
	{
		swap(num[start],num[end]);
		++start;
		--end;
	}
}

int main()
{
	int arr[] = {3,8,8,8};
	vector<int> num;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	nextPermutation(num);
	for(int i=0; i<num.size(); ++i)
		cout << num[i] << endl;
	return 0;
}
