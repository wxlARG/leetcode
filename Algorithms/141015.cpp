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

int func(vector<int> &num, int start, int end)
{
	if(start > end)
		return INT_MAX;

	int mid = start + (end-start)/2;

	if(num[mid] > num[start])
		return min(num[start],func(num,mid+1,end));
	else if(num[mid] == num[start])
		return min(num[start],func(num,mid+1,end));
	else 
		return min(num[mid],func(num,start,mid-1));
}

int findMin(vector<int> &num)
{
	return func(num,0,num.size()-1);
}

int main()
{
	int arr[] = {4,5,6,7,0,1,2};
	vector<int> num;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	int result = findMin(num);
	cout << result << endl;
	return 0;
}
