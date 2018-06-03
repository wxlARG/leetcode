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

int findPeakElement(const vector<int> &num)
{
	int start = 0;
	int end = num.size()-1;
	while(start!=end)
	{
		int mid = start+(end-start)/2;
		if(num[mid]>num[mid+1])
			end=mid;
		else
			start=mid+1;
	}
	return end;
}

int main()
{
	vector<int> num;
	int arr[] = {1, 2, 3, 1};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	int result = findPeakElement(num);
	cout << result << endl;
	return 0;
}
